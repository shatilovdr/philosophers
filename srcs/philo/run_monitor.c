/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:43:26 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/14 13:26:32 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static bool	check_philo(t_philo *philo);
static bool	check_if_all_full(t_philo *philo, int *n_full);

void	*run_monitor(void *arg)
{
	t_table	*table;
	t_philo	*philo;
	int		i;
	int		n_full;

	table = (t_table *)arg;
	while (get_value(table->mtx_table, &table->start) == 0)
		continue ;
	while (true)
	{
		i = 0;
		n_full = 0;
		while (i < table->n_philo)
		{
			philo = &table->philo[i++];
			if (check_if_all_full(philo, &n_full) == true)
				return (NULL);
			if (check_philo(philo) == false)
				return (NULL);
		}
	}
	return (NULL);
}

static bool	check_philo(t_philo *philo)
{
	long	curr;
	long	prev;

	curr = get_timestamp();
	prev = get_value(philo->mtx_philo, &philo->prev_meal);
	if (prev == 0)
		prev = philo->table->start;
	if (curr - prev > philo->table->t_die)
	{
		print_log(philo->table, curr, philo->id, DIED);
		return (false);
	}
	return (true);
}

static bool	check_if_all_full(t_philo *philo, int *n_full)
{
	t_table	*table;

	table = philo->table;
	if (philo->table->n_meals == -1)
		return (false);
	if (get_value(philo->mtx_philo, &philo->n_meals)
		>= philo->table->n_meals)
		*n_full = *n_full + 1;
	if (*n_full == philo->table->n_philo)
	{
		set_value(table->mtx_table, &table->finished, 1);
		return (true);
	}
	return (false);
}

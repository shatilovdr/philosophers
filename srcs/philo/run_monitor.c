/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:43:26 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/13 15:03:49 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static bool	check_philo(t_philo *philo);

void	*run_monitor(void *arg)
{
	t_table	*table;
	int		i;
	bool	status;

	table = (t_table *)arg;
	while (get_variable(table->mtx_table, &table->start) == 0)
		continue ;
	status = true;
	while (status)
	{
		i = 0;
		while (i < table->n_philo && status)
			status = check_philo(&table->philo[i++]);
	}
	set_variable(table->mtx_table, &table->finish, 1);
	return (NULL);
}

static bool	check_philo(t_philo *philo)
{
	size_t	curr;
	size_t	prev;

	curr = get_timestamp();
	prev = get_variable(philo->mtx_philo, &philo->prev_meal);
	if (curr - prev > 10)
	{
		printf("\033[41m%zu %d"DIED, curr, philo->id + 1);
		return (false);
	}
	return (true);
}

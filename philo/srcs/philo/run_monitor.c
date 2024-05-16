/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:43:26 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/17 09:56:06 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static int	check_philo(t_philo *philo);
static void	detach_all(t_table *table);

void	*run_monitor(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (get_value(table->mtx_table, &table->start) == 0)
		continue ;
	if (table->start == -1)
		return (NULL);
	ft_usleep(30);
	while (true)
	{
		i = 0;
		while (i < table->n_philo)
		{
			if (check_philo(&table->philo[i++]))
			{
				detach_all(table);
				return (NULL);
			}
		}
	}
	return (NULL);
}

static int	check_philo(t_philo *philo)
{
	long	curr;
	long	prev;

	pthread_mutex_lock(philo->table->mtx_table);
	if (philo->table->n_full == philo->table->n_philo)
	{
		philo->table->finished = 1;
		pthread_mutex_unlock(philo->table->mtx_table);
		return (1);
	}
	prev = get_value(philo->mtx_philo, &philo->prev_meal);
	if (prev == 0)
		prev = philo->table->start;
	curr = get_timestamp();
	if (curr - prev >= philo->table->t_die)
	{
		printf("%ld\t%d\t%s", curr - philo->table->start, philo->id + 1, DIED);
		philo->table->finished = 1;
	}
	pthread_mutex_unlock(philo->table->mtx_table);
	return (philo->table->finished);
}

static void	detach_all(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_detach(table->threads[i]);
		i++;
	}
}

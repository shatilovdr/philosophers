/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:53:46 by dshatilo          #+#    #+#             */
/*   Updated: 2024/08/18 10:01:56 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static void	join_all(t_table *table, int num);

int	run_simulation(t_table *table)
{
	int	i;

	pthread_mutex_lock(table->mtx_table);
	if (pthread_create(table->monitor, NULL, run_monitor, (void *) table) != 0)
	{
		pthread_mutex_unlock(table->mtx_table);
		return (1);
	}
	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&table->threads[i], NULL, run_philosopher,
				(void *) &((table->philo)[i])) != 0)
			break ;
		i++;
	}
	if (i == table->n_philo)
		table->start = get_timestamp();
	else
		table->start = -1;
	pthread_mutex_unlock(table->mtx_table);
	join_all(table, i);
	if (i != table->n_philo)
		return (1);
	return (0);
}

static void	join_all(t_table *table, int num)
{
	int	i;

	i = 0;
	pthread_join(*(table->monitor), NULL);
	while (i < num)
	{
		pthread_join(table->threads[i], NULL);
		i++;
	}
}

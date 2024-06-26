/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:53:46 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/20 13:39:02 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static void	join_all(t_table *table, int num);

int	run_simulation(t_table *table)
{
	int	i;

	if (pthread_create(table->monitor, NULL, run_monitor, (void *) table) != 0)
		return (1);
	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&table->threads[i], NULL, run_philosopher,
				(void *) &((table->philo)[i])) != 0)
			break ;
		i++;
	}
	if (i == table->n_philo)
		set_value(table->mtx_table, &table->start, get_timestamp());
	else
		set_value(table->mtx_table, &table->start, -1);
	join_all(table, i);
	if (i != table->n_philo)
		return (1);
	else
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

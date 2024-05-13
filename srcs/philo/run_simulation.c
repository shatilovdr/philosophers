/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:53:46 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/13 18:00:11 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

bool	run_simulation(t_table *table)
{
	int			i;
	pthread_t	*threads;
	pthread_t	monitor;

	threads = table->threads;
	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&threads[i], NULL, run_philosopher,
				(void *) &((table->philo)[i])) != 0)
			break ;
		i++;
	}
	if (pthread_create(&monitor, NULL, run_monitor, (void *) table) != 0)
		;//kill all
	if (i != table->n_philo)
		; //stop
	table->start = get_timestamp();
	i = 0;
	while (i < table->n_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (true);
}

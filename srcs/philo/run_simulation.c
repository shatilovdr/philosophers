/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:53:46 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/30 15:12:59 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

bool	run_simulation(t_table *table)
{
	int			i;
	pthread_t	*threads;

	threads = table->threads;
	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&threads[i], NULL, run_philosopher,
				(void *) &((table->philo)[i])) != 0)
			break ;
		i++;
	}
	table->start = get_timestamp();
	i = 0;
	while (i < table->n_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (true);
}

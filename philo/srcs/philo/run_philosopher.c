/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:21 by dshatilo          #+#    #+#             */
/*   Updated: 2024/06/29 19:43:25 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

int	wait_start(t_philo *philo);

void	*run_philosopher(void *arg)
{
	// t_philo	*philo;
	
	// philo = (t_philo *)arg;
	// if (wait_start(philo) == 1)
	// 	return (NULL);

	printf("%zu\n", get_timestamp());
	(void)arg;
	return (NULL);
}

int	wait_start(t_philo *philo)
{
	t_table	*table;
	long	start;

	table = philo->table;
	while (get_value(table->mtx_table, &table->start) == 0)
		continue ;
	start = table->start;
	if (start == -1)
		return (1);
	set_value(philo->mtx_philo, &philo->prev_meal, start);
	return (0);
}

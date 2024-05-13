/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:21 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/13 16:09:50 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static void	cycle_philosopher(t_philo *philo);

void	*run_philosopher(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (get_variable(philo->table->mtx_table, &philo->table->start) == 0)
		continue ;
	philo->prev_meal = philo->table->start;
	while (philo->n_meals < philo->table->n_meals
		|| philo->table->n_meals == -1)
		cycle_philosopher(philo);
	return (NULL);
}

static void	cycle_philosopher(t_philo *philo)
{
	printf("%zu %d"THINKING, get_timestamp(), philo->id + 1);
	pthread_mutex_lock(philo->fork_1);
	printf("%zu %d has taken a fork\n", get_timestamp(), philo->id + 1);
	pthread_mutex_lock(philo->fork_2);
	printf("%zu %d has taken a fork\n", get_timestamp(), philo->id + 1);
	set_variable(philo->mtx_philo, &philo->prev_meal, get_timestamp());
	printf("%zu %d"EATING, philo->prev_meal, philo->id + 1);
	usleep(philo->table->t_eat * 1000);
	pthread_mutex_unlock(philo->fork_1);
	pthread_mutex_unlock(philo->fork_2);
	philo->n_meals++;
	printf("%zu %d"SLEEPING, get_timestamp(), philo->id + 1);
	usleep(philo->table->t_sleep * 1000);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:21 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/30 15:25:04 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static size_t	is_ready(t_philo *philo);
static void		take_forks(t_philo *philo);

void	*run_philosopher(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (is_ready(philo) == 0)
		continue ;
	while (philo->n_meals < philo->table->n_meals
		|| philo->table->n_meals == -1)
	{
		take_forks(philo);
		printf("%zu %d "THINKING, get_timestamp(), philo->id);
	}
	return (NULL);
}

static size_t	is_ready(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(table->m_start);
	philo->prev_meal = table->start;
	pthread_mutex_unlock(table->m_start);
	return (philo->prev_meal);
}

static void	take_forks(t_philo *philo)
{
	t_mutex	*first;
	t_mutex	*second;

	if (philo->id != philo->table->n_philo - 1)
	{
		first = philo->l_fork;
		second = philo->r_fork;
	}
	else
	{
		first = philo->r_fork;
		second = philo->l_fork;
	}
	pthread_mutex_lock(first);
	printf("%zu %d has taken a fork\n", get_timestamp(), philo->id);
	pthread_mutex_lock(second);
	printf("%zu %d has taken a fork\n", get_timestamp(), philo->id);
	printf("%zu %d "EATING, get_timestamp(), philo->id);
	usleep(philo->table->t_eat * 1000);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
	philo->n_meals++;
	printf("%zu %d "SLEEPING, get_timestamp(), philo->id);
	usleep(philo->table->t_sleep * 1000);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:21 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/07 16:37:49 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"


static void		cycle_philosopher(t_philo *philo);
static void		set_forks_order(t_philo *philo, t_mutex **first,
					t_mutex **second);

void	*run_philosopher(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (is_ready(philo->table) == 0)
		continue ;
	philo->prev_meal = philo->table->start;
	while (philo->n_meals < philo->table->n_meals
		|| philo->table->n_meals == -1)
		cycle_philosopher(philo);
	return (NULL);
}

static void	cycle_philosopher(t_philo *philo)
{
	t_mutex	*first;
	t_mutex	*second;

	printf("%zu %d"THINKING, get_timestamp(), philo->id + 1);
	set_forks_order(philo, &first, &second);
	pthread_mutex_lock(first);
	printf("%zu %d has taken a fork\n", get_timestamp(), philo->id + 1);
	pthread_mutex_lock(second);
	printf("%zu %d has taken a fork\n", get_timestamp(), philo->id + 1);
	printf("%zu %d"EATING, get_timestamp(), philo->id + 1);
	usleep(philo->table->t_eat * 1000);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
	philo->n_meals++;
	printf("%zu %d"SLEEPING, get_timestamp(), philo->id + 1);
	usleep(philo->table->t_sleep * 1000);
}

static void	set_forks_order(t_philo *philo, t_mutex **first, t_mutex **second)
{
	if (philo->id != philo->table->n_philo - 1)
	{
		*first = philo->l_fork;
		*second = philo->r_fork;
	}
	else
	{
		*first = philo->r_fork;
		*second = philo->l_fork;
	}
}

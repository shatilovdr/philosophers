/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:21 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/29 18:30:13 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static bool	is_ready(t_table *table);
static void	take_forks(t_philo *philo);

void	*run_philosopher(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (is_ready(philo->table) == false)
		continue ;
	take_forks(philo);
	return (NULL);
}

static bool	is_ready(t_table *table)
{
	bool	status;

	pthread_mutex_lock(table->m_isready);
	status = table->isready;
	pthread_mutex_unlock(table->m_isready);
	return (true);
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
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
}

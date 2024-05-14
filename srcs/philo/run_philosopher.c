/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:21 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/14 18:16:47 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static void	cycle_philosopher(t_philo *philo);
static int	test(t_table *table);

void	*run_philosopher(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	while (get_value(philo->table->mtx_table, &philo->table->start) == 0)
		continue ;
	philo->prev_meal = philo->table->start;
	table = philo->table;
	if (philo->table->t_die == 0)
		return (NULL);
	while (get_value(table->mtx_table, &table->finished) == 0)
		cycle_philosopher(philo);
	return (NULL);
}

static void	cycle_philosopher(t_philo *philo)
{
	print_log(philo->table, get_timestamp(), philo->id, THINKING);
	if (philo->table->n_philo % 2 != 0 && philo->id % 2 != 0 && philo->n_meals != 0)
		ft_usleep(test(philo->table));
	pthread_mutex_lock(philo->fork_1);
	print_log(philo->table, get_timestamp(), philo->id, FORK_TAKEN);
	if (philo->table->n_philo == 1)
	{
		ft_usleep(philo->table->t_die);
		pthread_mutex_unlock(philo->fork_1);
		return ;
	}
	pthread_mutex_lock(philo->fork_2);
	print_log(philo->table, get_timestamp(), philo->id, FORK_TAKEN);
	set_value(philo->mtx_philo, &philo->prev_meal, get_timestamp());
	print_log(philo->table, philo->prev_meal, philo->id, EATING);
	ft_usleep(philo->table->t_eat);
	pthread_mutex_unlock(philo->fork_1);
	pthread_mutex_unlock(philo->fork_2);
	set_value(philo->mtx_philo, &philo->n_meals, philo->n_meals + 1);
	print_log(philo->table, get_timestamp(), philo->id, SLEEPING);
	ft_usleep(philo->table->t_sleep);
	return ;
}

static int	test(t_table *table)
{
	int	time;

	time = (table->t_die - table->t_eat - table->t_sleep) / 2;
	return (time * (time > 0));
}

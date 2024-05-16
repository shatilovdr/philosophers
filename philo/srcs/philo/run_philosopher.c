/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:21 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/16 14:26:19 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static int	wait_start(t_philo *philo);
static int	cycle_philosopher(t_philo *philo);
static int	eat(t_philo *philo);
static void	update_n_full(t_table *table);

void	*run_philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (wait_start(philo) == 1)
		return (NULL);
	if (philo->table->n_philo == 1)
	{
		print_log(philo, get_timestamp(), THINKING);
		pthread_mutex_lock(philo->fork_1);
		print_log(philo, get_timestamp(), FORK_TAKEN);
		ft_usleep(philo->table->t_die);
		pthread_mutex_unlock(philo->fork_1);
	}
	else
	{
		while (true)
			if (cycle_philosopher(philo) == 1)
				break ;
	}
	return (NULL);
}

static int	cycle_philosopher(t_philo *philo)
{
	if (print_log(philo, get_timestamp(), THINKING) == 1)
		return (1);
	if (philo->id % 2 != 0 && philo->n_meals == 0)
		ft_usleep(philo->table->t_eat / 2);
	if (philo->table->n_philo % 2 != 0
		&& philo->n_meals != 0)
		ft_usleep(philo->table->t_wait);
	if (eat(philo) == 1)
		return (1);
	if (print_log(philo, get_timestamp(), SLEEPING) == 1)
		return (1);
	ft_usleep(philo->table->t_sleep);
	return (0);
}

static int	wait_start(t_philo *philo)
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

static int	eat(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(philo->fork_1);
	if (print_log(philo, get_timestamp(), FORK_TAKEN) == 1)
	{
		pthread_mutex_unlock(philo->fork_1);
		return (1);
	}
	pthread_mutex_lock(philo->fork_2);
	if (print_log(philo, get_timestamp(), FORK_TAKEN) == 1)
	{
		pthread_mutex_unlock(philo->fork_1);
		pthread_mutex_unlock(philo->fork_2);
		return (1);
	}
	set_value(philo->mtx_philo, &philo->prev_meal, get_timestamp());
	status = print_log(philo, philo->prev_meal, EATING);
	if (status == 0)
		ft_usleep(philo->table->t_eat);
	philo->n_meals++;
	if (philo->n_meals == philo->table->n_meals)
		update_n_full(philo->table);
	pthread_mutex_unlock(philo->fork_1);
	pthread_mutex_unlock(philo->fork_2);
	return (status);
}

static void	update_n_full(t_table *table)
{
	pthread_mutex_lock(table->mtx_table);
	table->n_full += 1;
	pthread_mutex_unlock(table->mtx_table);
}

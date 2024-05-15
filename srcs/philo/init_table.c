/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:10:14 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/16 13:53:45 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static bool	init_philosophers(t_table *table);
static bool	init_threads(t_table *table);
static void	set_forks_order(t_philo *philo);

bool	init_table(int argc, char **argv, t_table *table)
{
	bool	status;

	status = check_args(argc, argv, table);
	if (status == true)
	{
		table->t_wait = (table->t_die - (table->t_eat + table->t_sleep)) / 2;
		if (table->t_wait < 0)
			table->t_wait = 0;
	}
	if (status == true)
		status = init_mutexes(&(table->mtx_forks), table->n_philo);
	if (status == true)
		status = init_mutexes(&(table->mtx_table), 1);
	if (status == true)
		status = init_mutexes(&(table->mtx_philo), table->n_philo);
	if (status == true)
		status = init_philosophers(table);
	if (status == true)
		status = init_threads(table);
	if (status == false)
		free_table(table);
	return (status);
}

static bool	init_philosophers(t_table *table)
{
	t_philo	*philo;
	int		n_philo;
	int		i;

	n_philo = table->n_philo;
	philo = ft_calloc(n_philo, sizeof(t_philo));
	if (!philo)
		return (false);
	i = 0;
	while (i < table->n_philo)
	{
		philo[i].id = i;
		philo[i].table = table;
		set_forks_order(&philo[i]);
		philo[i].mtx_philo = &table->mtx_philo[i];
		i++;
	}
	table->philo = philo;
	return (true);
}

static bool	init_threads(t_table *table)
{
	table->monitor = ft_calloc(1, sizeof(t_philo));
	if (!table->monitor)
		return (false);
	table->threads = ft_calloc(table->n_philo, sizeof(t_philo));
	if (!table->threads)
	{
		free(table->monitor);
		return (false);
	}
	return (true);
}

static void	set_forks_order(t_philo *philo)
{
	t_table	*table;
	int		n_philo;
	int		id;

	table = philo->table;
	n_philo = table->n_philo;
	id = philo->id;
	if (philo->id != n_philo - 1)
	{
		philo->fork_1 = &(table->mtx_forks[id]);
		philo->fork_2 = &(table->mtx_forks[(id - 1 + n_philo) % n_philo]);
	}
	else
	{
		philo->fork_1 = &(table->mtx_forks[(id - 1 + n_philo) % n_philo]);
		philo->fork_2 = &(table->mtx_forks[id]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:10:14 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/25 16:38:09 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static bool	init_philosophers(t_table *table);
static bool	init_threads(t_table *table);

bool	init_table(int argc, char **argv, t_table *table)
{
	bool	status;

	status = check_args(argc, argv, table);
	if (status == true)
		status = init_mutexes(&(table->forks), table->n_philo);
	if (status == true)
		status = init_mutexes(&(table->m_isready), 1);
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
	philo = ft_calloc(n_philo + 1, sizeof(t_philo));
	if (!philo)
		return (false);
	i = 0;
	while (i < table->n_philo)
	{
		(&philo[i])->l_fork = &(table->forks[i]);
		(&philo[i])->r_fork = &(table->forks[(i - 1 + n_philo) % n_philo]);
		i++;
	}
	table->philo = philo;
	return (true);
}

static bool	init_threads(t_table *table)
{
	table->threads = ft_calloc(table->n_philo + 1, sizeof(t_philo));
	if (!table->threads)
		return (false);
	return (true);
}

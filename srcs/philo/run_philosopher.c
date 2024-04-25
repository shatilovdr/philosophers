/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:06:21 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/25 18:29:59 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

static bool	is_ready(t_table *table);

void	*run_philosopher(void *arg)
{
	t_philo			*philo;
	struct timeval	tp;
	size_t			timestp;

	philo = (t_philo *)arg;
	while (is_ready(philo->table) == false)
		continue ;
	gettimeofday(&tp, NULL);
	timestp = tp.tv_sec * 1e6 + tp.tv_usec;
	printf("%zu\n", timestp);
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

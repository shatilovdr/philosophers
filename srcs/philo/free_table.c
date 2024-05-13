/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:05:27 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/13 13:56:30 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	free_table(t_table *table)
{
	if (table->mtx_forks)
		destroy_mutexes(table->mtx_forks, table->n_philo);
	if (table->mtx_table)
		destroy_mutexes(table->mtx_table, 1);
	if (table->mtx_philo)
		destroy_mutexes(table->mtx_philo, table->n_philo);
	if (table->philo)
		free(table->philo);
	if (table->threads)
		free(table->threads);
}

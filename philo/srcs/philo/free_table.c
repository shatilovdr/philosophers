/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:05:27 by dshatilo          #+#    #+#             */
/*   Updated: 2024/08/16 13:48:24 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	free_table(t_table *table)
{
	if (table->philo)
		free(table->philo);
	if (table->mtx_table)
		destroy_mutexes(table->mtx_table, 1);
	if (table->mtx_forks)
		destroy_mutexes(table->mtx_forks, table->n_philo);
	if (table->monitor)
		free(table->monitor);
	if (table->threads)
		free(table->threads);
}

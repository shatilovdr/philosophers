/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:05:27 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/30 15:14:34 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	free_table(t_table *table)
{
	if (table->forks)
		destroy_mutexes(table->forks, table->n_philo);
	if (table->m_start)
		destroy_mutexes(table->m_start, 1);
	if (table->philo)
		free(table->philo);
	if (table->threads)
		free(table->threads);
}

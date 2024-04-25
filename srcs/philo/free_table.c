/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:05:27 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/25 16:40:33 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	free_table(t_table *table)
{
	if (table->forks)
		destroy_mutexes(table->forks, table->n_philo);
	if (table->m_isready)
		destroy_mutexes(table->m_isready, 1);
	if (table->philo)
		free(table->philo);
	if (table->threads)
		free(table->threads);
}

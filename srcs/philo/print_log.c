/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:47:56 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/16 12:36:37 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

int	print_log(t_philo *philo, long timestamp, char *mode)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(table->mtx_table);
	if (table->finished == 0)
	{
		printf("%zu\t%d\t%s", timestamp - table->start, philo->id + 1, mode);
		pthread_mutex_unlock(table->mtx_table);
		return (0);
	}
	pthread_mutex_unlock(table->mtx_table);
	return (1);
}

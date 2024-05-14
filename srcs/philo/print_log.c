/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:47:56 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/14 12:30:52 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	print_log(t_table *table, long timestamp, int id, char *mode)
{
	pthread_mutex_lock(table->mtx_table);
	if (table->finished == 0)
		printf("%zu\t%d\t%s", timestamp, id + 1, mode);
	if (ft_strcmp(mode, DIED) == 0)
		table->finished = 1;
	pthread_mutex_unlock(table->mtx_table);
}

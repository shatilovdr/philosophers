/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:47:56 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/13 17:54:33 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	print_log(t_table *table, size_t timestamp, int id, char *mode)
{
	pthread_mutex_lock(table->mtx_table);
	if (table->finished == false)
		printf("%zu\t%d\t%s", timestamp, id + 1, mode);
	if (mode == DIED)
		table->finished = true;
	pthread_mutex_unlock(table->mtx_table);
}

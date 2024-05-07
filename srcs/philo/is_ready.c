/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ready.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:37:38 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/07 16:38:03 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

size_t	is_ready(t_table *table)
{
	size_t	start;

	pthread_mutex_lock(table->m_start);
	start = table->start;
	pthread_mutex_unlock(table->m_start);
	return (start);
}

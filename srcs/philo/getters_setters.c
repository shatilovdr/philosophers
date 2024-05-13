/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:37:38 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/13 11:54:50 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

size_t	get_variable(t_mutex *mutex, size_t *variable)
{
	size_t	value;

	pthread_mutex_lock(mutex);
	value = *variable;
	pthread_mutex_unlock(mutex);
	return (value);
}

void	set_variable(t_mutex *mutex, size_t *variable, size_t value)
{
	pthread_mutex_lock(mutex);
	*variable = value;
	pthread_mutex_unlock(mutex);
}

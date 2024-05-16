/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:37:38 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/14 13:14:45 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

long	get_value(t_mutex *mutex, long *variable)
{
	long	value;

	pthread_mutex_lock(mutex);
	value = *variable;
	pthread_mutex_unlock(mutex);
	return (value);
}

void	set_value(t_mutex *mutex, long *variable, long value)
{
	pthread_mutex_lock(mutex);
	*variable = value;
	pthread_mutex_unlock(mutex);
}

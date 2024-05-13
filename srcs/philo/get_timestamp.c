/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:09:02 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/13 09:51:59 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

size_t	get_timestamp(void)
{
	struct timeval	curr_time;
	size_t			timestamp;

	gettimeofday(&curr_time, NULL);
	timestamp = curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000;
	return (timestamp);
}

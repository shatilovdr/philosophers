/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:09:02 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/14 11:11:19 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

long	get_timestamp(void)
{
	struct timeval	curr_time;
	long			timestamp;

	gettimeofday(&curr_time, NULL);
	timestamp = curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000;
	return (timestamp);
}

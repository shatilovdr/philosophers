/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:09:02 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/29 18:29:50 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

size_t	get_timestamp(void)
{
	struct timeval	curr_time;
	int				timestamp;

	gettimeofday(&curr_time, NULL);
	timestamp = curr_time.tv_sec * 1000000 + curr_time.tv_usec;
	return (timestamp);
}

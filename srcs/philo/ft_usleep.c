/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:30:48 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/14 15:33:02 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	ft_usleep(int msec)
{
	long	start;

	start = get_timestamp();
	while (get_timestamp() - start < msec)
		usleep(500);
}

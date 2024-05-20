/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:30:48 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/20 13:36:14 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	ft_usleep(int msec, t_table *table)
{
	long	start;

	start = get_timestamp();
	while (get_timestamp() - start < msec
		&& get_value(table->mtx_table, &table->finished) == 0)
		usleep(500);
}

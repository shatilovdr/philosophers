/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:43:26 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/07 16:44:56 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

void	*run_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (is_ready(table) == 0)
		continue ;
	
	return (NULL);
}

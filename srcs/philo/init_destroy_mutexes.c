/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy_mutexes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:12:43 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/24 17:39:00 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

bool	init_mutexes(t_mutex **mutexes, int num)
{
	t_mutex	*tmp;
	int		i;

	tmp = ft_calloc(num, sizeof(t_mutex));
	if (!tmp)
		return (false);
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&(tmp[i]), NULL) != 0)
			break ;
		i++;
	}
	if (i == num)
	{
		*mutexes = tmp;
		return (true);
	}
	else
	{
		destroy_mutexes(tmp, i);
		return (false);
	}
}

void	destroy_mutexes(t_mutex *mutexes, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&mutexes[i]);
		i++;
	}
	free(mutexes);
}

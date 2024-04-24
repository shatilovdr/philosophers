/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:10:14 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/24 19:05:25 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

bool	init_philo(int argc, char **argv, t_philo *philo)
{
	bool	status;

	status = check_args(argc, argv, philo);
	if (status == true)
		status = init_mutexes(&(philo->forks), philo->n_philo);
	if (status == true)
		status = init_mutexes(&(philo->m_isready), 1);
	if (status == false)
		free_philo(philo);
	return (status);
}

void	free_philo(t_philo *philo)
{
	if (philo.)
	if (philo->forks)
		destroy_mutexes();
}

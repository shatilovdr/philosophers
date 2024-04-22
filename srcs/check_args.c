/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:28:29 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/22 17:26:51 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

int	check_arg(char	*arg);

void	check_args(int argc, char **argv, t_philo **philo)
{
	*philo = ft_calloc(1, sizeof(t_philo));
	if (!*philo)
		exit(1);
	if (argc != 5 && argc != 6)
	{
		printf("INVALID NUMBER OF ARGUMENTS!\nexit.\n");
		free(*philo);
		exit(1);
	}
	(*philo)->n_philo = check_arg(argv[1]);
	(*philo)->t_die = check_arg(argv[2]);
	(*philo)->t_eat = check_arg(argv[3]);
	(*philo)->t_sleep = check_arg(argv[4]);
	if (argc == 6)
		(*philo)->n_meals = check_arg(argv[5]);
	else
		(*philo)->n_meals = -1;
	if ((*philo)->n_philo < 1 || (*philo)->t_die < 0 || (*philo)->t_eat < 0
		|| (*philo)->t_sleep < 0 || (argc == 6 && (*philo)->n_meals < 0))
	{
		printf("Incorrect argument detected.\nexit.\n");
		free(*philo);
		exit(1);
	}
}

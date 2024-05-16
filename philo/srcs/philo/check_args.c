/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:28:29 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/16 11:46:38 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

bool	check_args(int argc, char **argv, t_table *table)
{
	if (argc != 5 && argc != 6)
	{
		write(STDERR_FILENO, "INVALID NUMBER OF ARGUMENTS!\nexit.\n", 35);
		exit(1);
	}
	table->n_philo = check_arg(argv[1]);
	table->t_die = check_arg(argv[2]);
	table->t_eat = check_arg(argv[3]);
	table->t_sleep = check_arg(argv[4]);
	if (argc == 6)
		table->n_meals = check_arg(argv[5]);
	else
		table->n_meals = -1;
	if (table->n_philo < 1 || table->t_die < 1 || table->t_eat < 1
		|| table->t_sleep < 1 || (argc == 6 && table->n_meals < 1))
	{
		write(STDERR_FILENO, "Incorrect argument detected.\nexit.\n", 35);
		exit(1);
	}
	return (true);
}

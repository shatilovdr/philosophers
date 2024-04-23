/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:28:29 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/23 14:58:04 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

int	check_arg(char	*arg);

void	check_args(int argc, char **argv, t_input **input)
{
	*input = ft_calloc(1, sizeof(t_input));
	if (!*input)
		exit(1);
	if (argc != 5 && argc != 6)
	{
		printf("INVALID NUMBER OF ARGUMENTS!\nexit.\n");
		free(*input);
		exit(1);
	}
	(*input)->n_philo = check_arg(argv[1]);
	(*input)->t_die = check_arg(argv[2]);
	(*input)->t_eat = check_arg(argv[3]);
	(*input)->t_sleep = check_arg(argv[4]);
	if (argc == 6)
		(*input)->n_meals = check_arg(argv[5]);
	else
		(*input)->n_meals = -1;
	if ((*input)->n_philo < 1 || (*input)->t_die < 0 || (*input)->t_eat < 0
		|| (*input)->t_sleep < 0 || (argc == 6 && (*input)->n_meals < 0))
	{
		printf("Incorrect argument detected.\nexit.\n");
		free(*input);
		exit(1);
	}
}

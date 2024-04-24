/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:11:10 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/24 17:34:48 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	philo = (t_philo){0};
	init_philo(argc, argv, &philo);
	return (0);
}

// pthread_mutex_t mutex;

// t_bool	check_is_ready(t_bool *is_ready)
// {
// 	t_bool	status;

// 	pthread_mutex_lock(&mutex);
// 	status = *is_ready;
// 	pthread_mutex_unlock(&mutex);
// 	return (status);
// }

// void	*routine(void *arg)
// {
// 	t_bool	*status;
// 	struct timeval tp;
// 	size_t	timestp;

// 	status = (t_bool *) arg;
// 	while (check_is_ready(status) == false)
// 		continue ;
// 	gettimeofday(&tp, NULL);
// 	timestp = tp.tv_sec * 1e6 + tp.tv_usec;
// 	printf("%zu\n", timestp);
// 	return (NULL);
// }

// int	main(int argc, char **argv)
// {
// 	// t_philo		*philo;
// 	(void)argc;
// 	t_bool		is_ready;
// 	int	num = 	atoi(argv[1]);
// 	pthread_t	threads[num];

// 	pthread_mutex_init(&mutex, NULL);
// 	int i = 0;
// 	is_ready = false;
// 	while (i <num)
// 	{
// 		pthread_create(&threads[i], NULL, routine, (void *) &is_ready);
// 		i++;
// 	}
// 	is_ready = true;
// 	i = 0;
// 	while (i <num)
// 	{
// 		pthread_join(threads[i], NULL);
// 		i++;
// 	}
// 	// check_args(argc, argv, &philo);
// 	return (0);
// }

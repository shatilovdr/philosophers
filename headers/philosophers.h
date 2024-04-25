/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:41 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/25 18:16:41 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "helpers.h"
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

typedef struct s_philo
{
	t_mutex			*l_fork;
	t_mutex			*r_fork;
	int				n_meals;
	size_t			prev_meal;
	t_table			*table;
}	t_philo;

struct	s_table
{
	int			n_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_meals;
	bool		isready;
	t_mutex		*m_isready;
	t_mutex		*forks;
	t_philo		*philo;
	pthread_t	*threads;
};

bool	init_table(int argc, char **argv, t_table *table);
bool	check_args(int argc, char **argv, t_table *table);
int		check_arg(char *arg);
bool	init_mutexes(t_mutex **mutexes, int num);
void	destroy_mutexes(t_mutex *mutexes, int num);
void	free_table(t_table *table);
bool	run_simulation(t_table *table);
void	*run_philosopher(void *arg);

#endif
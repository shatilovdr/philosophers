/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:41 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/07 11:04:43 by dshatilo         ###   ########.fr       */
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
	int				id;
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
	size_t		start;
	bool		isfinished; //
	t_mutex		*m_start;
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
size_t	get_timestamp(void);

# ifndef EATING
#  define EATING " \033[42mis eating\033[0m\n"
# endif

# ifndef SLEEPING
#  define SLEEPING " \033[44mis sleeping\033[0m\n"
# endif

# ifndef THINKING
#  define THINKING " \033[45mis thinking\033[0m\n"
# endif

# ifndef DIED
#  define DIED "died\033[0m\n"
# endif

#endif
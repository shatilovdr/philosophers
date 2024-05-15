/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:41 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/16 10:55:54 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "helpers.h"
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	t_mutex			*fork_1;
	t_mutex			*fork_2;
	long			n_meals;
	long			prev_meal;
	t_mutex			*mtx_philo;
	t_table			*table;
}	t_philo;

struct	s_table
{
	int			n_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	long		n_meals;
	long		n_full;
	int			t_wait;
	long		start;
	long		finished;
	t_philo		*philo;
	t_mutex		*mtx_table;
	t_mutex		*mtx_forks;
	t_mutex		*mtx_philo;
	pthread_t	*monitor;
	pthread_t	*threads;
};

bool	init_table(int argc, char **argv, t_table *table);
bool	check_args(int argc, char **argv, t_table *table);
int		check_arg(char *arg);
bool	init_mutexes(t_mutex **mutexes, int num);
void	destroy_mutexes(t_mutex *mutexes, int num);
void	free_table(t_table *table);
int		run_simulation(t_table *table);
long	get_value(t_mutex *mutex, long *variable);
void	set_value(t_mutex *mutex, long *variable, long value);
void	*run_monitor(void *arg);
void	*run_philosopher(void *arg);
long	get_timestamp(void);
int		print_log(t_philo *philo, long timestamp, char *mode);
void	ft_usleep(int msec);

# ifndef EATING
#  define EATING "\033[42m\033[30mis eating\033[0m\n"
# endif

# ifndef SLEEPING
#  define SLEEPING "\033[46m\033[30mis sleeping\033[0m\n"
# endif

# ifndef THINKING
#  define THINKING "\033[45m\033[30mis thinking\033[0m\n"
# endif

# ifndef DIED
#  define DIED "\033[41m\033[30mdied\033[0m\n"
# endif

# ifndef FORK_TAKEN
#  define FORK_TAKEN "\033[43m\033[30mhas taken a fork\033[0m\n"
# endif

#endif
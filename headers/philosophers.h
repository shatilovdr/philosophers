/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:41 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/23 15:08:22 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "helpers.h"
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_input
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_meals;
}	t_input;

void	init_philo(int argc, char **argv);
void	check_args(int argc, char **argv, t_input **philo);
int		check_arg(char *arg);

// void	check_args(int argc, char **argv, t_philo **philo);
// int		ft_atoi(const char *str);
// int		ft_isdigit(int ch);
// int		ft_isspace(int ch);
// void	ft_putchar_fd(char c, int fd);
// void	ft_putendl_fd(char *s, int fd);
// void	ft_putnbr_fd(int n, int fd);
// void	ft_putstr_fd(char *s, int fd);
// void	*ft_memset(void *s, int c, size_t n);
// void	*ft_calloc(size_t count, size_t size);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:16:01 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/19 14:00:35 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

t_bool	check_atoi(int num, char *str);

int	check_arg(char *arg)
{
	int	num;

	num = ft_atoi(arg);
	if (check_atoi(num, arg) == false)
		return (-1);
	return (num);
}

t_bool	check_atoi(int num, char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (num == 0)
	{
		if (*str != '0')
			return (-1);
		while (*str == '0')
			str++;
	}
	else
	{
		while (ft_isdigit(*str) != 0)
			str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (false);
	return (true);
}

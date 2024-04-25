/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:44:41 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/25 17:29:07 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
#include <unistd.h>

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
int		ft_isdigit(int ch);
int		ft_isspace(int ch);
#endif
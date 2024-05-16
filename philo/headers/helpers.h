/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:44:41 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/14 10:22:40 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
int		ft_isdigit(int ch);
int		ft_isspace(int ch);
int		ft_strcmp(const char *s1, const char *s2);
#endif
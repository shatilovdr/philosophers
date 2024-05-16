/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:04:53 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/14 10:21:13 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/helpers.h"

/**
 * @brief	A function that compare two strings (like original strcmp)
 * @param	s1 first string
 * @param	s2 second string
 * @return	an integer greater than, equal to, or less than 0, according as
 * the string s1 is greater than, equal to, or less than the string s2
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] != 0)
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i])
			return ((unsigned char) s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s2[i] != 0)
		return (0 - (unsigned char)s2[i]);
	else
		return (0);
}

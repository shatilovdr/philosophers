/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:34 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/23 14:59:37 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/helpers.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	num;

	num = (size_t)-1;
	if (count != 0 && (num / count) < size)
		return (0);
	num = count * size;
	mem = malloc(num);
	if (!mem)
		return (0);
	memset(mem, 0, num);
	return (mem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:34 by dshatilo          #+#    #+#             */
/*   Updated: 2024/04/19 13:34:12 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

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
	ft_memset(mem, 0, num);
	return (mem);
}

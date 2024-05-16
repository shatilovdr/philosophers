/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:11:10 by dshatilo          #+#    #+#             */
/*   Updated: 2024/05/16 10:12:06 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;
	bool	status;

	table = (t_table){0};
	status = init_table(argc, argv, &table);
	if (status == true)
	{
		status = run_simulation(&table);
		free_table(&table);
	}
	return (status != true);
}

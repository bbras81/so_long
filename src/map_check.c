/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:31:40 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/13 11:51:32 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_rectangle(char **map)
{
	size_t	first_line;
	int		counter;

	counter = 1;
	first_line = ft_strlen(map[0]);
	while (map[counter])
	{
		if(ft_strlen(map[counter]) != first_line)
			print_error("The map must be rectangular");
		counter++;
	}
	return (0);
}

int	check_map(char **map)
{
	is_rectangle(map);
	return (0);
}

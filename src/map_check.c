/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:31:40 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/13 12:56:48 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_len_ch(char **map)
{
	int	counter;

	counter = 0;
	while (*map)
	{
		counter++;
		map++;
	}
	return (counter);
}

static int	is_rectangle(char **map)
{
	size_t	first_line;
	int		counter;

	counter = 1;
	first_line = ft_strlen(map[0]);
	while (map[counter])
	{
		if (ft_strlen(map[counter]) != first_line)
		{
			if (ft_strlen(map[counter]) == 0)
				print_error("Map contains empty lines");
			else
				print_error("The map must be rectangular");
		}
		counter++;
	}
	return (0);
}
static void	check_walls(char **map)
{
	int	height;
	int	width;
	int	i;
	int	j;

	height = map_len_ch(map);
	width = ft_strlen(map[0]);
	j = 0;
	while (j < width)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
			print_error("Map is not surrounded by walls");
		j++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			print_error("Map is not surrounded by walls");
		i++;
	}
}

int	check_map(char **map)
{
	is_rectangle(map);
	check_walls(map);
	return (0);
}

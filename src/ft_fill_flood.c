/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flood.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-17 22:12:31 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/18 15:04:36 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_len_arr(char **map)
{
	int	i;

	i = 0;
	if (!map)
		print_error_free("Map not found", map);
	while (map[i])
		i++;
	return (i);
}

char	**cpy_char(char **map)
{
	int		i;
	int		map_len;
	char	**cpy_map;

	i = 0;
	map_len = map_len_arr(map);
	cpy_map = malloc(sizeof(char *) * (map_len + 1));
	if (!cpy_map)
	{
		print_error_free("Allocation error", cpy_map);
	}
	while (map[i])
	{
		cpy_map[i] = ft_strdup(map[i]);
		i++;
	}
	cpy_map[i] = NULL;
	return (cpy_map);
}
void	get_player(char **map, int *i, int *j)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*i = y;
				*j = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(char **cpy_map, int i, int j)
{
	if (i < 0 || j < 0 || i >= map_len_arr(cpy_map) || j >= (int)ft_strlen(cpy_map[i]))
		return ;
	if (cpy_map[i][j] == '1' || cpy_map[i][j] == 'V')
		return ;
	cpy_map[i][j] = 'V';
	flood_fill(cpy_map, i + 1, j);
	flood_fill(cpy_map, i - 1, j);
	flood_fill(cpy_map, i, j + 1);
	flood_fill(cpy_map, i, j - 1);
}

void	check_reachable(char **cpy_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cpy_map[i])
	{
		while (cpy_map[i][j])
		{
			if (cpy_map[i][j] == 'C' || cpy_map[i][j] == 'E')
				print_error("Not all collectibles or exit are reachable");
      j++;
		}
    j = 0;
    i++;
	}
}

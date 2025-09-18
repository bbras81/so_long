/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flood.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-17 22:12:31 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/18 13:27:26 by brunmigu         ###   ########.fr       */
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

void flood_fill(char **cpy_map, int i, int j)
{

}

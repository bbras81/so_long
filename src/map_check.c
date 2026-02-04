/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:31:40 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/18 15:27:04 by brunmigu         ###   ########.fr       */
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
				print_error_free("Map contains empty lines", map);
			else
				print_error_free("The map must be rectangular", map);
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
			print_error_free("Map is not surrounded by walls", map);
		j++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			print_error_free("Map is not surrounded by walls", map);
		i++;
	}
}

static int	is_valid_char(char chr, int *c, int *e, int *p)
{
	if (chr == 'C')
	{
		(*c)++;
		return (0);
	}
	else if (chr == 'E')
	{
		(*e)++;
		return (0);
	}
	else if (chr == 'P')
	{
		(*p)++;
		return (0);
	}
	else if (chr == '1' || chr == '0')
		return (0);
	else
		return (1);
}
static int	check_char(int *c, int *e, int *p)
{
	if (*c >= 1 && *e == 1 && *p == 1)
		return (0);
	return (1);
}

static void	check_content(char **map)
{
	int	count_p;
	int	count_e;
	int	count_c;
	int	i;
	int	j;

	count_p = 0;
	count_e = 0;
	count_c = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (is_valid_char(map[i][j], &count_c, &count_e, &count_p))
				print_error_free("Is not a valid character", map);
			j++;
		}
		j = 0;
		i++;
	}
	if (check_char(&count_c, &count_e, &count_p))
		print_error_free("Map with wrong characters", map);
}

int	check_map(char **map)
{
	int		i;
	int		j;
	char	**cpy_map;

	i = 0;
	j = 0;
	is_rectangle(map);
	check_walls(map);
	check_content(map);
	cpy_map = cpy_char(map);
  change_to_null(cpy_map);
	get_player(map, &i, &j);
	flood_fill(cpy_map, i, j);
	check_reachable(cpy_map);
	map_free(cpy_map);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 08:59:20 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/13 12:26:50 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_len(char *arg)
{
	int		fd;
	char	*file_content;
	int		map_len;

	map_len = 0;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		print_error("Could not open map file.");
	while ((file_content = get_next_line(fd)) != NULL)
	{
		map_len++;
		free(file_content);
	}
	close(fd);
	return (map_len);
}
static void	change_to_null(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map)
		print_error("Change to nul!");
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		j = 0;
		i++;
	}
}

char	**open_map(int len, char *arg)
{
	int		i;
	char	**map;
	char	*file_content;
	int		fd;

	i = 0;
	map = NULL;
	if (!arg)
		print_error("No map file provided.");
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		print_error("Allocation error");
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		print_error("Could not open map file.");
	while ((file_content = get_next_line(fd)) != NULL)
	{
		map[i] = file_content;
		i++;
	}
	map[i] = NULL;
	close(fd);
	change_to_null(map);
	return (map);
}

int	map_free(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

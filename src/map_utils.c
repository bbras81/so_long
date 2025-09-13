/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 08:59:20 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/13 10:00:57 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

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
	return (map);
}

int	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

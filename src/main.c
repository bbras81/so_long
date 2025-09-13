/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 08:47:48 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/13 13:32:30 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	init_game(char *arg)
{
	int		len_map;
	char	**map;

	len_map = map_len(arg);
	if (len_map <= 0)
		print_error("Map file is empty.");
	map = open_map(len_map, arg);
	check_map(map);
	map_free(map);
	return (0);
}

int	main(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		print_error("Wrong number of arguments. Usage: ./so_long <map.ber>");
	len = ft_strlen(argv[1]);
	if (len <= 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		print_error("Invalid file extension. Must be .ber");
	if (init_game(argv[1]) != 0)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 08:47:48 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/13 11:43:47 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	init_game(char *arg)
{
	int		len_map;
	int		y;
	char	**map;

	y = 0;
	len_map = map_len(arg);
	map = open_map(len_map, arg);
	check_map(map);
	while (map[y])
	{
		ft_printf("%s", map[y]);
		y++;
	}
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
	if (!init_game(argv[1]))
		return (1);
	return (0);
}

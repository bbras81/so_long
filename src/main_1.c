/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 08:47:10 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/13 08:47:42 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	validate_args(int argc, char *arg)
{
	int	len;

	if (argc != 2)
		print_error("Wrong number of arguments. Usage: ./so_long <map.ber>");
	len = ft_strlen(arg);
	if (len <= 4 || ft_strncmp(arg + len - 4, ".ber", 4) != 0)
		print_error("Invalid file extension. Must be .ber");
}

static void	validate_map(char *arg)
{
	int		fd;
	int		fst_len;
	char	*line;

	fst_len = 0;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		print_error("Could not open map file.");
	while ((line = get_next_line(fd)) != NULL)
	{
		fst_len++;
		free(line);
	}
	close(fd);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		print_error("Could not open map file.");
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s\n", line);
		free(line);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	validate_args(argc, argv[1]);
	validate_map(argv[1]);
	return (0);
}

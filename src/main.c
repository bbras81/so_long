/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 07:59:47 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/12 19:00:48 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	validate_args(int argc, char *arg)
{
	int	len;
	int	fd;

	if (argc != 2)
		print_error("Wrong number of arguments. Usage: ./so_long <map.ber>");
	len = ft_strlen(arg);
	if (len <= 4 || ft_strncmp(arg + len - 4, ".ber", 4) != 0)
		print_error("Invalid file extension. Must be .ber");
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		print_error("Could not open map file.");
	close(fd);
	return (fd);
}

static void	validate_map(int fd)
{
	char	*line;
	int		fst_len;

	fst_len = 0;
	while (get_next_line(fd) != NULL)
		fst_len++;
	ft_printf("Len da Matrix %d\n", fst_len);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s\n", line);
		free(line);
	}
}
int	main(int argc, char **argv)
{
	int	fd;

	fd = validate_args(argc, argv[1]);
	validate_map(fd);
	return (0);
}

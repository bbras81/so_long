/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 07:59:18 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/18 15:10:05 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

void	print_error(char *msg);
void	print_error_free(char *msg, char **map);
int		map_len(char *arg);
char	**open_map(int len, char *arg);
int		map_free(char **map);
int		check_map(char **map);
char	**cpy_char(char **map);
void	get_player(char **map, int *i, int *j);
int		map_len_arr(char **map);
void	flood_fill(char **cpy_map, int i, int j);
void	check_reachable(char **cpy_map);
void	change_to_null(char **map);
#endif // !SO_LONG_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 07:59:18 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/13 09:13:37 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

void	print_error(char *msg);
int		map_len(char *arg);
char	**open_map(int len, char *arg);
int		map_free(char **map);
#endif // !SO_LONG_H

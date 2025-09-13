/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 08:59:20 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/13 09:13:05 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_path(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		print_error("Could not open map file.");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flood.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-17 22:12:31 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/17 23:53:45 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_player(char **map, int *i, int *j)
{

	while (map[*i])
	{
		while (map[*i][*j])
		{
      if (map[*i][*j] == 'P')
        break;
      (*j)++;
		}
    *j = 0;
    (*i)++;
	}
}



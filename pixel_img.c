/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunmigu <brunmigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:37:07 by brunmigu          #+#    #+#             */
/*   Updated: 2025/09/09 23:55:53 by brunmigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_image_render(t_data *img)
{
	
	int	x;
	int	y;

	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			my_mlx_pixel_put(img, x, y, 0x0000FF00); // verde
			y++;
		}
		x++;
	}
}

void	draw_circle(t_data *img, int cx, int cy, int r, int color)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	x = cx - r;
	while (x <= cx + r)
	{
		y = cy - r;
		while (y <= cy + r)
		{
			dx = x - cx;
			dy = y - cy;
			if (dx * dx + dy * dy <= r * r)
				my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}
int	key_hook(int keycode, t_data *img)
{
	printf("Keycode: %d\n", keycode);
	return (0);
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// desenhar fundo
	my_image_render(&img);
	// desenhar círculo vermelho no centro
	draw_circle(&img, 1000, 540, 200, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_loop(mlx);
}

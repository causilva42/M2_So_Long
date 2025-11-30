/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:41:48 by causilva          #+#    #+#             */
/*   Updated: 2025/08/29 14:47:44 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <math.h>
#include <stdlib.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_vars;

unsigned int	linear_to_wheel(float x)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	float			wheel_pos;

	wheel_pos = fmod(x, 1) * 6;
	r = 0;
	if (wheel_pos < 1 || wheel_pos >= 5)
		r = 255;
	else if (wheel_pos >= 4)
		r = 255 * (wheel_pos - 4);
	else if (wheel_pos < 2)
		r = 255 * (2 - wheel_pos);
	g = 0;
	if (wheel_pos >= 1 && wheel_pos < 3)
		g = 255;
	else if (wheel_pos < 1)
		g = 255 * wheel_pos;
	else if (wheel_pos < 4)
		g = 255 * (4 - wheel_pos);
	b = 0;
	if (wheel_pos >= 3 && wheel_pos < 5)
		b = 255;
	else if (wheel_pos >= 5)
		b = 255 * (6 - wheel_pos);
	else if (wheel_pos >= 2)
		b = 255 * (wheel_pos - 2);
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	//mlx_destroy_display(vars->mlx); ????
	free(vars->mlx);
	exit (0);
}

int	loop(t_img *img)
{
	(void)img;
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		x;
	int		y;
	int		color;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	x = 0;
	while (x < 1920)
	{
		y = 0;
		while (y < 1080)
		{
			color = linear_to_wheel((float)(x) / 1920);
			my_mlx_pixel_put(&vars.img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 17, 0L, close, &vars);
	mlx_loop_hook(vars.mlx, loop, &vars.img);
	mlx_loop(vars.mlx);
	return (0);
}

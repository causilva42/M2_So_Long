/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:42:31 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 12:04:25 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		put_component(char comp, t_img *sprite, t_vars *vars);
static int		put_square(t_coord posic_map, t_img *sprite, t_vars *vars);

int	next_frame(t_vars *vars)
{
	static int	offset = 0;

	put_component('0', &vars->sprites[0], vars);
	put_component('1', &vars->sprites[1], vars);
	put_component('C', &vars->sprites[2], vars);
	put_component('E', &vars->sprites[3], vars);
	put_component('P', &vars->sprites[4], vars);
	if (vars->finished)
	{
		ft_img_func_put(&vars->main_img, (t_coord){offset, 0},
			(t_coord){WIN_MAX_SIZE_X, WIN_MAX_SIZE_Y}, &linear_to_color_wheel);
		ft_img_func_put(&vars->main_img, (t_coord){offset - WIN_MAX_SIZE_X, 0},
			(t_coord){WIN_MAX_SIZE_X, WIN_MAX_SIZE_Y}, &linear_to_color_wheel);
		offset += 10;
		if (offset == WIN_MAX_SIZE_X)
			offset = 0;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->main_img.img, 0, 0);
	return (0);
}

static int	put_component(char comp, t_img *sprite, t_vars *vars)
{
	t_coord	posic_map;
	t_map	map;

	map = vars->map;
	posic_map.y = 0;
	while (posic_map.y < map.size.y)
	{
		posic_map.x = 0;
		while (posic_map.x < map.size.x)
		{
			if (map.data[posic_map.y * map.size.x + posic_map.x] == comp)
				put_square(posic_map, sprite, vars);
			posic_map.x++;
		}
		posic_map.y++;
	}
	return (0);
}

static int	put_square(t_coord posic_map, t_img *sprite, t_vars *vars)
{
	t_coordf	square_size;
	t_coord		posic_img_init;
	t_coord		posic_img_end;
	t_coord		square_size_round;
	t_map		map;

	map = vars->map;
	square_size.x = (float) vars->win_size.x / map.size.x;
	square_size.y = (float) vars->win_size.y / map.size.y;
	posic_img_init.x = square_size.x * posic_map.x;
	posic_img_init.y = square_size.y * posic_map.y;
	posic_img_end.x = square_size.x * (posic_map.x + 1);
	posic_img_end.y = square_size.y * (posic_map.y + 1);
	square_size_round.x = posic_img_end.x - posic_img_init.x;
	square_size_round.y = posic_img_end.y - posic_img_init.y;
	ft_img_img_put(&vars->main_img, posic_img_init, square_size_round, sprite);
	return (0);
}

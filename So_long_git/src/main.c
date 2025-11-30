/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:41:48 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:36:48 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		init_vars(t_vars *vars, char *filename);
static t_coord	get_win_size(t_coord map_size);
static int		init_sprites(t_vars *vars);
int				my_close(t_vars *vars);

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (ft_printf("Error\nMain: number of args != 2\n"), 1);
	if (init_vars(&vars, argv[1]) == -1)
		return (1);
	mlx_hook(vars.win, 17, 0L, my_close, &vars);
	mlx_key_hook(vars.win, key_handler, &vars);
	mlx_loop_hook(vars.mlx, next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

static int	init_vars(t_vars *vars, char *filename)
{
	if (parse_map(&(vars->map), filename) == -1)
		return (-1);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (my_close(vars)
			, ft_printf("Error\nInit_vars: failed to init mlx\n"), -1);
	vars->win_size = get_win_size(vars->map.size);
	vars->win = mlx_new_window(vars->mlx,
			vars->win_size.x, vars->win_size.y, "So_Long");
	if (!vars->win)
		return (my_close(vars),
			ft_printf("Error\nInit_vars: failed to open window\n"), -1);
	if (ft_my_new_image(vars->mlx, &vars->main_img, vars->win_size) == -1)
		return (my_close(vars)
			, ft_printf("Error\nInit_vars: failed to create image\n"), -1);
	if (init_sprites(vars) == -1)
		return (my_close(vars), -1);
	vars->move_count = 0;
	vars->finished = 0;
	return (0);
}

static t_coord	get_win_size(t_coord map_size)
{
	float	win_ratio;

	win_ratio = (float) map_size.x / map_size.y;
	if (win_ratio >= (float) WIN_MAX_SIZE_X / WIN_MAX_SIZE_Y)
		return ((t_coord){WIN_MAX_SIZE_X, (int)(WIN_MAX_SIZE_X / win_ratio)});
	else
		return ((t_coord){(int)(WIN_MAX_SIZE_Y * win_ratio), WIN_MAX_SIZE_Y});
}

static int	init_sprites(t_vars *vars)
{
	vars->sprites[0].img = NULL;
	vars->sprites[1].img = NULL;
	vars->sprites[2].img = NULL;
	vars->sprites[3].img = NULL;
	vars->sprites[4].img = NULL;
	if (ft_my_file_to_image(vars->mlx, &vars->sprites[0]
			, "_textures/water.xpm") == -1)
		return (ft_printf("Error\nInit_sprites: failed to open image 1\n"), -1);
	if (ft_my_file_to_image(vars->mlx, &vars->sprites[1]
			, "_textures/wall.xpm") == -1)
		return (ft_printf("Error\nInit_sprites: failed to open image 2\n"), -1);
	if (ft_my_file_to_image(vars->mlx, &vars->sprites[2]
			, "_textures/fruit.xpm") == -1)
		return (ft_printf("Error\nInit_sprites: failed to open image 3\n"), -1);
	if (ft_my_file_to_image(vars->mlx, &vars->sprites[3]
			, "_textures/E.xpm") == -1)
		return (ft_printf("Error\nInit_sprites: failed to open image 4\n"), -1);
	if (ft_my_file_to_image(vars->mlx, &vars->sprites[4]
			, "_textures/dolphin.xpm") == -1)
		return (ft_printf("Error\nInit_sprites: failed to open image 5\n"), -1);
	return (0);
}

int	my_close(t_vars *vars)
{
	int	x;

	if (vars->map.data)
		free(vars->map.data);
	if (vars->mlx)
	{
		if (vars->main_img.img)
			mlx_destroy_image(vars->mlx, vars->main_img.img);
		x = -1;
		while (++x < 5)
		{
			if (vars->sprites[x].img)
				mlx_destroy_image(vars->mlx, vars->sprites[x].img);
		}
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:46:40 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:28:16 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "../mlx_extended/mlx/mlx.h"
# include "../mlx_extended/libft_mlx/libft_mlx.h"
# include "../libft_extended/ft_printf/ft_printf.h"
# include "../libft_extended/get_next_line/get_next_line.h"
# include "../libft_extended/libft/libft.h"

# define WIN_MAX_SIZE_X 1920
# define WIN_MAX_SIZE_Y 800
/* 
typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;
 */
typedef struct s_map
{
	char	*data;
	t_coord	size;
	t_coord	player;
	t_coord	exit;
	int		collectibles_count;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_coord	win_size;
	t_map	map;
	t_img	main_img;
	t_img	sprites[5];
	int		move_count;
	int		finished;
}	t_vars;

int		my_close(t_vars *vars);
int		parse_map(t_map *map, char *filename);
int		key_handler(int keycode, t_vars *vars);
int		next_frame(t_vars *vars);

char	*ft_rmbreak(char *s);
int		half_gray(t_coordf x);
int		all_black(t_coordf x);

#endif
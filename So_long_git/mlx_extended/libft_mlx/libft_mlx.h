/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:54:41 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:54:14 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MLX_H
# define LIBFT_MLX_H

# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_coordf
{
	float	x;
	float	y;
}	t_coordf;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	t_coord	size;
	int		line_length;
	int		endian;
}	t_img;

void	ft_img_func_put(t_img *img,
			t_coord pos, t_coord size, int (*f)(t_coordf));
void	ft_img_img_put(t_img *img, t_coord pos, t_coord size, t_img *img2);
int		ft_img_pixel_get(t_img *img, t_coord pos);
void	ft_img_pixel_put_special(t_img *img, t_coord pos, int color);
void	ft_img_pixel_put(t_img *img, t_coord pos, int color);
int		ft_my_file_to_image(void *mlx, t_img *img, char *filename);
int		ft_my_new_image(void *mlx, t_img *img, t_coord size);

int		linear_to_color_wheel(t_coordf wheel_pos);

#endif
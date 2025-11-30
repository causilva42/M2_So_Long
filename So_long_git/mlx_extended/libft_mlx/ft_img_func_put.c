/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_func_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:08:54 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:50:58 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

void	ft_img_func_put(t_img *img,
	t_coord pos, t_coord size, int (*f)(t_coordf))
{
	int			x;
	int			y;
	int			color;

	if (!img || !img->addr || !f)
		return ;
	y = 0;
	while (y != size.y)
	{
		x = 0;
		while (x != size.x)
		{
			if ((pos.x + x >= 0) && (pos.x + x < img->size.x)
				&& (pos.y + y >= 0) && (pos.y + y < img->size.y))
			{
				color = f((t_coordf){(float)(x) / size.x, (float)(y) / size.y});
				ft_img_pixel_put_special(img,
					(t_coord){pos.x + x, pos.y + y}, color);
			}
			x += (size.x > 0) - (size.x < 0);
		}
		y += (size.y > 0) - (size.y < 0);
	}
}

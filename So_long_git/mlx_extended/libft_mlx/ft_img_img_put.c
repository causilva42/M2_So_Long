/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_img_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:03:01 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:51:37 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

void	ft_img_img_put(t_img *img, t_coord pos, t_coord size, t_img *img2)
{
	int			x;
	int			y;
	t_coord		sub_pos;
	int			color;

	if (!img || !img->addr || !img2 || !img2->addr)
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
				sub_pos.x = (int)(((float)(x) / size.x) * img2->size.x);
				sub_pos.y = (int)(((float)(y) / size.y) * img2->size.y);
				color = ft_img_pixel_get(img2, sub_pos);
				ft_img_pixel_put(img, (t_coord){pos.x + x, pos.y + y}, color);
			}
			x += (size.x > 0) - (size.x < 0);
		}
		y += (size.y > 0) - (size.y < 0);
	}
}
/* 
void	ft_img_img_put(t_img *img, t_coord pos, t_img *img2)
{
	int			x;
	int			y;
	int			color;

	if(!img || !img->addr || !img2 || !img2->addr)
		return ;
	y = 0;
	while (y != size.y)
	{
		x = 0;
		while (x != size.x)
		{
			if ((pos.x + x >= 0) && (pos.x + x < img->size.x)
				&& (pos.y + y >= 0) && (pos.y + y < img->size.y) )
			{
				color = ft_img_pixel_get(img2, (t_coord){x, y});
				ft_img_pixel_put(img, (t_coord){pos.x + x, pos.y + y}, color);
			}
			x += (size.x > 0) - (size.x < 0);
		}
		y += (size.y > 0) - (size.y < 0);
	}
}
 */
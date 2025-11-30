/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:42:25 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:20:27 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

void	ft_img_pixel_put(t_img *img, t_coord pos, int color)
{
	char	*dst;

	dst = img->addr + (pos.y * img->line_length + pos.x * (img->bpp / 8));
	*(int *)dst = color;
}

/* 
void	ft_img_pixel_put(t_img *img, t_coord pos, int color)
{
	char	*dst;

	if((img && img->addr)
		&& (pos.x >= 0) && (pos.x < img->size.x)
		&& (pos.y >= 0) && (pos.y < img->size.y))
	{
		dst = img->addr + (pos.y * img->line_length + pos.x * (img->bpp / 8));
		*(int *)dst = color;
	}
}
 */
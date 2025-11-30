/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_pixel_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:42:22 by causilva          #+#    #+#             */
/*   Updated: 2025/09/23 15:06:18 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

int	ft_img_pixel_get(t_img *img, t_coord pos)
{
	char	*dst;

	dst = img->addr + (pos.y * img->line_length + pos.x * (img->bpp / 8));
	return (*(int *)dst);
}
/* 
int	ft_img_pixel_get(t_img *img, t_coord pos)
{
	char	*dst;

	if((img && img->addr)
		&& (pos.x >= 0) && (pos.x < img->size.x)
		&& (pos.y >= 0) && (pos.y < img->size.y))
	{
		dst = img->addr + (pos.y * img->size.x + pos.x * (img->bpp / 8));
		return (*(int *)dst);
	}
	return (0);
}
 */
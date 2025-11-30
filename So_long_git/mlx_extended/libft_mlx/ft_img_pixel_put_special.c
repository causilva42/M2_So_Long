/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_pixel_put_special.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:59:45 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:57:29 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

// Assumes dst_alpha == 0xFF
void	ft_img_pixel_put_special(t_img *img, t_coord pos, int color)
{
	char			*dst;
	float			a;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	dst = img->addr + (pos.y * img->line_length + pos.x * (img->bpp / 8));
	a = 1 - (float)((unsigned)color >> 24) / 255;
	r = (((unsigned)color >> 16) & 0xFF) * a;
	r += ((*(unsigned *)dst >> 16) & 0xFF) * (1 - a);
	g = (((unsigned)color >> 8) & 0xFF) * a;
	g += ((*(unsigned *)dst >> 8) & 0xFF) * (1 - a);
	b = (((unsigned)color >> 0) & 0xFF) * a;
	b += ((*(unsigned *)dst >> 0) & 0xFF) * (1 - a);
	*(unsigned *)dst = (r << 16 | g << 8 | b);
}
/* 
void	ft_img_pixel_put(t_img *img, t_coord pos, int color)
{
	char		*dst;
	float		a[3];
	unsigned	r[3];
	unsigned	g[3];
	unsigned	b[3];

	dst = img->addr + (pos.y * img->line_length + pos.x * (img->bpp / 8));
	a[0] = (*(unsigned *)dst >> 24) / 255;
	r[0] = ((*(unsigned *)dst >> 16) & 0xFF) * a[0];
	g[0] = ((*(unsigned *)dst >> 8) & 0xFF) * a[0];
	b[0] = ((*(unsigned *)dst >> 0) & 0xFF) * a[0];
	a[1] = ((unsigned)color >> 24) / 255;
	r[1] = (((unsigned)color >> 16) & 0xFF) * a[1];
	g[1] = (((unsigned)color >> 8) & 0xFF) * a[1];
	b[1] = (((unsigned)color >> 0) & 0xFF) * a[1];
	a[2] = a[0] + a[1] - (a[0] * a[1]);
	if (!a[2])
		return ;
	r[2] = (r[0] * (1 - a[1]) + r[1]) / a[2];
	g[2] = (g[0] * (1 - a[1]) + g[1]) / a[2];
	b[2] = (b[0] * (1 - a[1]) + b[1]) / a[2];
	*(unsigned *)dst = ((unsigned)(a[2] * 255) << 24);
	*(unsigned *)dst |= (r[2] << 16 | g[2] << 8 | b[2]);
}
 */
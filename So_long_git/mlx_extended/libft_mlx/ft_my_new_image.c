/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_new_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:38:35 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:55:16 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

int	ft_my_new_image(void *mlx, t_img *img, t_coord size)
{
	if (!mlx || !img)
		return (-1);
	img->img = mlx_new_image(mlx, size.x, size.y);
	if (!img->img)
		return (-1);
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_length, &img->endian);
	img->size = size;
	return (0);
}

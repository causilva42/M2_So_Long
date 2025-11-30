/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_file_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:58:23 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:56:22 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

int	ft_my_file_to_image(void *mlx, t_img *img, char *filename)
{
	if (!mlx || !img)
		return (-1);
	img->img = mlx_xpm_file_to_image(mlx, filename, &img->size.x, &img->size.y);
	if (!img->img)
		return (-1);
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_length, &img->endian);
	return (0);
}

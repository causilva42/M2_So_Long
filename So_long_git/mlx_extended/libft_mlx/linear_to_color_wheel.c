/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_to_color_wheel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:01:44 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 12:00:04 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

// Gets a float and based on its decimal value returns a 
// 	trgb unsigned int (with t = 0) from the collor whell.
// 
// Uses math.h (fmod)

static float	distance_in_wheel(float reference, float value)
{
	float	distance;

	distance = value - reference;
	distance *= (distance > 0) - (distance < 0);
	distance -= (distance > 3) * (distance - 3) * 2;
	return (distance);
}

int	linear_to_color_wheel(t_coordf wheel_pos)
{
	float			dist;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	wheel_pos.x = fmod(wheel_pos.x, 1) * 6;
	dist = distance_in_wheel(0, wheel_pos.x);
	r = (dist < 1) * 255 + (dist >= 1 && dist < 2) * (2 - dist) * 255;
	dist = distance_in_wheel(2, wheel_pos.x);
	g = (dist < 1) * 255 + (dist >= 1 && dist < 2) * (2 - dist) * 255;
	dist = distance_in_wheel(4, wheel_pos.x);
	b = (dist < 1) * 255 + (dist >= 1 && dist < 2) * (2 - dist) * 255;
	return ((int)(0x80 << 24 | r << 16 | g << 8 | b));
}

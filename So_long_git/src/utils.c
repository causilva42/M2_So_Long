/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:37:02 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:28:52 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_rmbreak(char *s)
{
	int	len;

	if (s)
	{
		len = ft_strlen(s);
		if (s[len - 1] == '\n')
			s[len - 1] = '\0';
	}
	return (s);
}

int	half_gray(t_coordf x)
{
	(void)x;
	return ((int)(0x80U << 24));
}

int	all_black(t_coordf x)
{
	(void)x;
	return (0);
}

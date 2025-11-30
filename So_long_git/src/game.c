/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:46:20 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:29:00 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move(t_coord direction, t_vars *vars);

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		return (my_close(vars), 0);
	if (!vars->finished)
	{
		if (keycode == 119 || keycode == 65362)
			move((t_coord){0, -1}, vars);
		else if (keycode == 97 || keycode == 65361)
			move((t_coord){-1, 0}, vars);
		else if (keycode == 115 || keycode == 65364)
			move((t_coord){0, 1}, vars);
		else if (keycode == 100 || keycode == 65363)
			move((t_coord){1, 0}, vars);
	}
	return (0);
}

static int	move(t_coord direction, t_vars *vars)
{
	int	current_addr;
	int	move_addr;

	current_addr = vars->map.player.y * vars->map.size.x + vars->map.player.x;
	move_addr = current_addr + direction.y * vars->map.size.x + direction.x;
	if (vars->map.data[move_addr] == '1'
		|| (vars->map.data[move_addr] == 'E' && vars->map.collectibles_count))
		return (0);
	if (vars->map.data[move_addr] == 'C')
		vars->map.collectibles_count--;
	if (vars->map.data[move_addr] == 'E')
		vars->finished = 1;
	vars->move_count++;
	ft_printf("Number of movements: %d\n", vars->move_count);
	vars->map.data[current_addr] = '0';
	vars->map.data[move_addr] = 'P';
	vars->map.player.x += direction.x;
	vars->map.player.y += direction.y;
	return (0);
}

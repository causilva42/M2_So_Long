/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:20:53 by causilva          #+#    #+#             */
/*   Updated: 2025/09/24 11:41:00 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fill_map_data(t_map *map, int fd);
static int	check_map_data(t_map *map);
static int	check_valid_path(t_map *map);
static int	recur_check(t_map *map_dup, t_coord pos);

int	parse_map(t_map *map, char *filename)
{
	int	fd;

	map->data = NULL;
	map->size = (t_coord){0, 0};
	map->player = (t_coord){-1, -1};
	map->exit = (t_coord){-1, -1};
	map->collectibles_count = 0;
	if (ft_strcmp(filename + ft_strlen(filename) - 4, ".ber") != 0)
		return (ft_printf("Error\nParse_map: file.ext != .ber\n"), -1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nParse_map: failed to open file\n"), -1);
	if (fill_map_data(map, fd) == -1)
		return (close(fd), -1);
	close(fd);
	if (check_map_data(map) == -1)
		return (free(map->data), -1);
	if (check_valid_path(map) == -1)
		return (free(map->data), -1);
	return (0);
}

static int	fill_map_data(t_map *map, int fd)
{
	char	*temp;
	char	*data_cpy;

	map->data = NULL;
	data_cpy = NULL;
	temp = ft_rmbreak(get_next_line(fd));
	if (!temp)
		return (ft_printf("Error\nFill_map_data: empty file\n"), -1);
	map->size.x = ft_strlen(temp);
	while (temp != NULL)
	{
		if ((int)ft_strlen(temp) != map->size.x)
			return (ft_printf("Error\nFill_map_data: size.x varies\n"),
				free(map->data), free(temp), -1);
		map->size.y++;
		map->data = ft_strjoin(data_cpy, temp);
		if (!map->data)
			return (ft_printf("Error\nFill_map_data: failed to join\n"),
				free(data_cpy), free(temp), -1);
		free(data_cpy);
		free(temp);
		data_cpy = map->data;
		temp = ft_rmbreak(get_next_line(fd));
	}
	return (0);
}

static int	check_map_data(t_map *map)
{
	int	i;

	i = -1;
	while (map->data[++i])
	{
		if ((i < map->size.x || i >= map->size.x * (map->size.y - 1)
				|| i % map->size.x == 0 || i % map->size.x == map->size.x - 1
			) && map->data[i] != '1')
			return (ft_printf("Error\nCheck_map_data: map not enclosed\n"), -1);
		if (map->data[i] == 'C')
			map->collectibles_count++;
		else if (map->data[i] == 'E' && map->exit.x == -1)
			map->exit = (t_coord){i % map->size.x, i / map->size.x};
		else if (map->data[i] == 'E')
			return (ft_printf("Error\nCheck_map_data: multiple exits\n"), -1);
		else if (map->data[i] == 'P' && map->player.x == -1)
			map->player = (t_coord){i % map->size.x, i / map->size.x};
		else if (map->data[i] == 'P')
			return (ft_printf("Error\nCheck_map_data: multiple players\n"), -1);
		else if (map->data[i] != '0' && map->data[i] != '1')
			return (ft_printf("Error\nCheck_map_data: invalid char\n"), -1);
	}
	if (map->exit.x == -1 || map->player.x == -1 || map->collectibles_count < 1)
		return (ft_printf("Error\nCheck_map_data: lacks one of (C/E/P)\n"), -1);
	return (0);
}

static int	check_valid_path(t_map *map)
{
	t_map	map_dup;

	map_dup = *map;
	map_dup.data = ft_strdup(map->data);
	if (!map_dup.data)
		return (ft_printf("Error\nCheck_valid_path: failed to dup\n"), -1);
	if (recur_check(&map_dup, map_dup.player) == 0)
	{
		ft_printf("Error\nCheck_valid_path: valid path not found\n");
		return (free(map_dup.data), -1);
	}
	if (map_dup.collectibles_count > 0)
	{
		ft_printf("Error\nCheck_valid_path: unreachable collectible\n");
		return (free(map_dup.data), -1);
	}
	free(map_dup.data);
	return (0);
}

static int	recur_check(t_map *map_dup, t_coord pos)
{
	if (map_dup->data[pos.y * map_dup->size.x + pos.x] == '1'
		|| map_dup->data[pos.y * map_dup->size.x + pos.x] == 'X')
		return (0);
	if (map_dup->data[pos.y * map_dup->size.x + pos.x] == 'E')
		return (1);
	if (map_dup->data[pos.y * map_dup->size.x + pos.x] == 'C')
		map_dup->collectibles_count--;
	map_dup->data[pos.y * map_dup->size.x + pos.x] = 'X';
	return (recur_check(map_dup, (t_coord){pos.x + 1, pos.y})
		+ recur_check(map_dup, (t_coord){pos.x, pos.y + 1})
		+ recur_check(map_dup, (t_coord){pos.x - 1, pos.y})
		+ recur_check(map_dup, (t_coord){pos.x, pos.y - 1}));
}

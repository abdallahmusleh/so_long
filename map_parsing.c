/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:41:29 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/25 14:51:55 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	height_finder(t_map *map)
{
	int		count;

	count = 0;
	while (map->grid[count])
		count++;
	map->height = count;
	return (count);
}

int	check_rectangle(t_map *map)
{
	int	i;

	i = 0;
	map->width = ft_strlen(map->grid[i]);
	i = 1;
	while (i < map->height)
	{
		if (ft_strlen(map->grid[i]) != map->width)
			return (-1);
		i++;
	}
	return (0);
}

int	wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map->width))
	{
		if (map->grid[0][i] != '1' || map->grid[(map->height) - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < (map->height))
	{
		if (map->grid[i][0] != '1' || map->grid[i][(map->width) - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	player_exit_collectible_checker(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
				map->count_player++;
			if (map->grid[y][x] == 'E')
				map->count_exit++;
			if (map->grid[y][x] == 'C')
				map->count_collectible++;
			x++;
		}
		y++;
	}
	if (map->count_player != 1 || map->count_collectible == 0
		|| map->count_exit != 1)
		return (-1);
	return (0);
}

int	unknown_character_checker(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] != 'C' && map->grid[y][x] != 'E'
					&& map->grid[y][x] != 'P' && map->grid[y][x] != '0'
						&& map->grid[y][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

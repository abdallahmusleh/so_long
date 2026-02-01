/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:30:15 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/23 18:50:37 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
}

static char	**tmp_map(char **map, int map_height)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (map_height + 1));
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_tab(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	player_position_finder(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static int	validate_path(char **map_copy, char **original)
{
	int	y;
	int	x;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if ((original[y][x] == 'C' || original[y][x] == 'E')
				&& map_copy[y][x] != 'X')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	path_checker(t_map *map)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = tmp_map(map->grid, map->height);
	if (!map_copy)
		return (-1);
	player_position_finder(map_copy, &x, &y);
	flood_fill(map_copy, x, y);
	if (validate_path(map_copy, map->grid) == -1)
	{
		free_tab(map_copy);
		return (-1);
	}
	free_tab(map_copy);
	return (0);
}

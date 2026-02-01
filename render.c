/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 21:40:00 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/21 21:35:39 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_map *game, int x, int y)
{
	char	cell;

	cell = game->grid[y][x];
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (cell == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (cell == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collect, x * TILE_SIZE, y * TILE_SIZE);
	else if (cell == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
	else if (cell == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, x * TILE_SIZE, y * TILE_SIZE);
}

int	render_map(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

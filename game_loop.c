/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 21:42:00 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/23 19:02:29 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_move_count(int moves)
{
	ft_printf("Moves: %d\n", moves);
}

static void	update_tiles(t_map *game, int new_x, int new_y, char target)
{
	game->grid[game->player_y][game->player_x] = game->player_tile;
	if (target == 'E')
		game->player_tile = 'E';
	else if (target == 'C')
		game->player_tile = '0';
	else
		game->player_tile = target;
	game->grid[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
}

static void	apply_move(t_map *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_y < 0 || !game->grid[new_y]
		|| !game->grid[new_y][new_x])
		return ;
	target = game->grid[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'C')
		game->count_collectible--;
	update_tiles(game, new_x, new_y, target);
	game->moves++;
	print_move_count(game->moves);
	if (target == 'E' && game->count_collectible == 0)
		close_game(game);
	render_map(game);
}

int	handle_key(int keycode, t_map *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 65362 || keycode == 119)
		apply_move(game, 0, -1);
	else if (keycode == 65364 || keycode == 115)
		apply_move(game, 0, 1);
	else if (keycode == 65361 || keycode == 97)
		apply_move(game, -1, 0);
	else if (keycode == 65363 || keycode == 100)
		apply_move(game, 1, 0);
	return (0);
}

int	close_game(t_map *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_tab(game->grid);
	free(game);
	exit(0);
}

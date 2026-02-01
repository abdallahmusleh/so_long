/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:33:41 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/25 14:34:10 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	initializer(t_map *game)
{
	game->count_player = 0;
	game->count_collectible = 0;
	game->count_exit = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->moves = 0;
	game->player_tile = '0';
	return (1);
}

static int	validate_map(t_map *game)
{
	int	i;

	if (height_finder(game) < 3)
		return (-1);
	if (check_rectangle(game) == -1)
		return (-1);
	i = 0;
	while (i < game->height)
		i++;
	if (wall(game) == -1)
		return (-1);
	if (player_exit_collectible_checker(game) == -1)
		return (-1);
	if (path_checker(game) == -1)
		return (-1);
	if (unknown_character_checker(game) == -1)
		return (-1);
	return (0);
}

static void	free_and_errors(char **grid, t_map *game, char *str)
{
	free_tab(grid);
	free(game);
	errors(str);
}

int	main(int argc, char **argv)
{
	t_map	*game;

	if (argc != 2 || ft_strncmp(".ber", &argv[1][ft_strlen(argv[1]) - 4],
		ft_strlen(argv[1]) - 4))
		return (errors("Error\n"));
	game = malloc(sizeof(t_map));
	if (!game)
		return (errors("Error\n"));
	initializer(game);
	game->grid = map_creation(argv[1]);
	if (!game->grid || validate_map(game) == -1)
		free_and_errors(game->grid, game, "Error\nInvalid map\n");
	if (init_mlx(game) == -1)
		free_and_errors(game->grid, game, "Error\nMLX initialization failed\n");
	render_map(game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	free_tab(game->grid);
	free(game);
	return (0);
}

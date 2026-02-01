/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:01:02 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/25 14:33:13 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define TILE_SIZE 64

# include <fcntl.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		count_player;
	int		count_collectible;
	int		count_exit;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		player_x;
	int		player_y;
	int		moves;
	char	player_tile;
}			t_map;

char		*get_next_line(int fd);
int			ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, int start, int len);
int			ft_strncmp(char *s1, char *s2, int n);
char		**map_creation(char argv[]);
char		**ft_split(char const *s, char c);
int			errors(char *str);
void		free_tab(char **tab);
int			height_finder(t_map *map);
int			check_rectangle(t_map *map);
int			wall(t_map *map);
int			player_exit_collectible_checker(t_map *map);
int			path_checker(t_map *map);
void		player_position_finder(char **map, int *x, int *y);
int			init_mlx(t_map *game);
int			render_map(t_map *game);
int			handle_key(int keycode, t_map *game);
int			close_game(t_map *game);
int			voidpointer(unsigned long i);
int			ft_putstr(char *s);
int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_putnbr_unsigned(unsigned int n);
int			hexadecimal_upper(unsigned int i);
int			hexadecimal_lower(unsigned int i);
int			ft_printf(const char *placeholders, ...);
int			unknown_character_checker(t_map *map);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:55:25 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/23 19:07:45 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_map_string(int fd)
{
	char	*all;
	char	*line;

	all = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		all = ft_strjoin(all, line);
		free(line);
		if (!all)
			return (NULL);
		line = get_next_line(fd);
	}
	return (all);
}

char	**map_creation(char argv[])
{
	int		fd;
	char	*initial_map;
	char	**map_2d;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	initial_map = read_map_string(fd);
	close(fd);
	if (!initial_map)
		return (NULL);
	map_2d = ft_split(initial_map, '\n');
	if (!map_2d)
	{
		free(initial_map);
		return (NULL);
	}
	free(initial_map);
	return (map_2d);
}

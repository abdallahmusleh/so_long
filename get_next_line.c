/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:03:51 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/22 16:45:41 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*tempjoin(char *buf, char *leftover)
{
	char	*temp;

	temp = ft_strjoin(leftover, buf);
	return (temp);
}

static char	*extract_line(char *leftover)
{
	int		i;
	int		x;
	char	*line_new;

	i = 0;
	x = 0;
	if (!leftover || leftover[0] == '\0')
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	line_new = malloc(i + 1);
	if (!line_new)
		return (NULL);
	while (x < i)
	{
		line_new[x] = leftover[x];
		x++;
	}
	line_new[x] = '\0';
	return (line_new);
}

static char	*update_leftover(char *leftover)
{
	int		i;
	char	*new_leftover;

	i = 0;
	if (!leftover)
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\0')
	{
		free(leftover);
		return (NULL);
	}
	new_leftover = ft_substr(leftover, (i + 1), ft_strlen(leftover) - i);
	free(leftover);
	if (!new_leftover || new_leftover[0] == '\0')
	{
		free(new_leftover);
		return (NULL);
	}
	return (new_leftover);
}

char	*readfunction(char *buf, char *leftover, int fd)
{
	int	char_read;

	char_read = 1;
	while (char_read > 0 && leftover && !ft_strchr(leftover, '\n'))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buf);
			if (leftover)
				free(leftover);
			return (NULL);
		}
		buf[char_read] = '\0';
		leftover = tempjoin(buf, leftover);
		if (!leftover)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line_returned;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!leftover)
		leftover = ft_strdup("");
	leftover = readfunction(buf, leftover, fd);
	if (!leftover)
		return (NULL);
	line_returned = extract_line(leftover);
	if (line_returned)
	{
		leftover = update_leftover(leftover);
		return (line_returned);
	}
	free(leftover);
	leftover = NULL;
	return (NULL);
}

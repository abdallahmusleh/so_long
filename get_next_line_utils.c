/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:05:33 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/22 16:43:05 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/* char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	x;
	char	*newstring;

	i = -1;
	x = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	newstring = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstring)
	{
		return (NULL);
	}
	while (s1[++i])
		newstring[i] = s1[i];
	while (s2[++x])
		newstring[i + x] = s2[x];
	newstring[i + x] = '\0';
	return (newstring);
} */
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (res == NULL)
	{
		if (s1)
			free (s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*mal;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (s[i])
		i++;
	mal = malloc((i + 1) * sizeof(char));
	if (!mal)
		return (NULL);
	while (s[x])
	{
		mal[x] = s[x];
		x++;
	}
	mal[x] = '\0';
	return (mal);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		x;
	char	*string;

	x = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		return (ft_strdup(""));
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	string = malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (s[start] && x < len)
	{
		string[x] = s[start + x];
		x++;
	}
	string[x] = '\0';
	return (string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:35:40 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/27 10:40:55 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char	*s)
{
	char	*str;
	char	*tmp;
	int		i;

	if (!(tmp = malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	str = tmp;
	free(tmp);
	return (str);
}

char	*ft_strjoin(char *s, char *c)
{
	int		i;
	char	*str;
	char	*tmp;

	if (!(tmp = (char *)malloc(ft_strlen(s) + 2)))
		return (0);
	i = 0;
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = c[0];
	tmp[i + 1] = '\0';
	str = tmp;
	free(tmp);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char	buffer[1];
	int		flag;

	if (!line || !(*line = ft_strdup("")))
		return (-1);
	while ((flag = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n' || buffer[0] == '\0')
		{
			buffer[0] = '\0';
			break ;
		}
		*line = ft_strjoin(*line, buffer);
	}
	buffer[0] = '\0';
	return (flag);
}

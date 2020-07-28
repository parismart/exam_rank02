/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:35:40 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/28 12:25:21 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s, char *c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char *)malloc(i + 2)))
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c[0];
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char	buffer[1];
	int		flag;

	if (!line || !(*line = malloc(1)))
		return (-1);
	*line[0] = '\0';
	while ((flag = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n' || buffer[0] == '\0')
			break ;
		*line = ft_strjoin(*line, buffer);
	}
	buffer[0] = '\0';
	return (flag);
}

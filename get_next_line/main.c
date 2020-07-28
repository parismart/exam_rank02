/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:04:40 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/28 12:23:58 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int		fd;
	int		flag;
	char	*line;

	fd = open("gnltest.txt", O_RDONLY);
	while ((flag = get_next_line(fd, &line)) > 0)
	{
		printf("%d - ", flag);
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%d - ", flag);
	printf("%s", line);
	free(line);
	line = NULL;
	close(fd);
	return (0);
}

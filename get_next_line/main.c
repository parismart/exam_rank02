/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:04:40 by parmarti          #+#    #+#             */
/*   Updated: 2020/08/05 21:02:35 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		flag;
	char	*line;

	while ((flag = get_next_line(&line)) > 0)
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
	return (0);
}

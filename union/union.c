/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:52:13 by parmarti          #+#    #+#             */
/*   Updated: 2020/08/05 21:04:10 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int	ascii[255];
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			ascii[i++] = 0;
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (ascii[(int)argv[i][j]] == 0)
				{
					ascii[(int)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

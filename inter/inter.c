/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:37:04 by parmarti          #+#    #+#             */
/*   Updated: 2020/08/05 20:54:07 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	inter(const char *s1, const char *s2)
{
	unsigned int	ascii[255];
	unsigned int	i;

	i = 0;
	while (i < 255)
		ascii[i++] = 0;
	i = 0;
	while (s2[i])
	{
		if (ascii[(int)s2[i]] == 0)
			ascii[(int)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (ascii[(int)s1[i]] == 1)
		{
			ascii[(int)s1[i]] = 2;
			write(1, &s1[i], 1);
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

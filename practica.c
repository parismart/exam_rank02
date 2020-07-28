/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practica.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti </var/mail/parmarti>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 09:52:03 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/28 12:33:16 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	used[255];
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		while(i < 255)
			used[i++] = 0;
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (used[(unsigned char)argv[i][j]] == 0)
				{
					used[(unsigned char)argv[i][j]] = 1;
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

int main(int argc, char **argv)
{
	int	used[255];
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		while (1 < 255)
			used[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && used[(unsigned char)argv[i][j]] == 0)
					used[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && used[(unsigned char)argv[i][j]] == 1)
				{
					used[(unsigned char)argv[i][j]] = 2;
					write (1, &argv[i][j], 1);
				}
				j++;
			}
			i--;
		}
	}
	write (1, "\n", 1);
	return (0);
}


char	*ft_strjoin(char *s, char *c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(str = malloc(i + 2)))
		return (NULL);
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

int		get_next_line(**line)
{
	char	buffer[1];
	int		flag;

	if (!line || (!(*line = malloc(1)))
		return (-1);)
	*line[0] = '\0';
	while ((flag = read(0, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n' || buffer[0] == '\0')
			break ;
		*line = ft_strjoin(*line, buffer);
	}
	buffer[0] = '\0';
	return (flag);
}

int		ft_nbrlen(long long n, int base_len)
{
	int	i;

	i = 1;
	while (n >= base_len)
	{
		n = n / base_len;
		i++;
	}
	return (i);
}	

void	ft_putnbr(long long n, int base_len, char *base)
{
	if (n >= base_len)
		putnbr_base(n / base_len, base_len, base);
	write (1, base[n % base_len], 1);
}

int		ft_printf(char *format, ...)
{
	va_list	args;
	char	*str;
	char	*s;
	char	*base;
	long	nbr;
	int		base_len;
	int		n;
	int		neg;
	int		width;
	int		prec;
	int		flag_prec;
	int		spaces;
	int		zeros;
	int		length;

	va_start(args, format);
	str = format;
	s = NULL;
	base = NULL;
	nbr = 0;
	base_len = 0;
	n = 0;
	neg = 0;
	width = 0;
	prec = 0;
	flag+prec = 0;
	spaces = 0;
	zeros = 0;
	length = 0;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + (*str - 48);
				str++;
			}
			if (*str == '.')
			{
				str++;
				flag_prec = 1;
				while (*str >= '0' && *str <= '9')
				{
					prec = prec * 10 + (*str - 48);
					str++;
				}
			}
			if (*str == 's')
			{
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				while (s[n])
					n++;
			}
			if (*str == 'd')
			{
				nbr = va_arg(args, int);
				base_len = 10;
				base = "0123456789"
				if (nbr < 0)
				{
					nbr = -nbr;
					neg = 1;
				}
				n = ft_nbrlen(nbr, base_len) + neg;
			}
			if (*str == 'x')
			{
				nbr = va_arg(args, unsigned);
				base_len = 16;
				base = "0123456789abcdef"
				n = ft_nbrlen(nbr, base_len);
			}
			if (flag_prec == 1 && prec > n && *str != 's')
				zeros = prec - n + neg;
			else if (flag_prec == 1 && prec < n && *str == 's')
				n = prec;
			else if (flag_prec == 1 && prec == 0 && (*str == 's' || nbr == 0))
				n = 0;
			spaces = width - zeros - n;
			while (spaces-- > 0)
			{
				write(1, " ", 1);
				length++;
			}
			if (neg == 1)
				write(1, "-", 1);
			while (zeros-- > 0)
			{
				write(1, "0", 1);
				length++;
			}
			if (*str == 's')
				write(1, s, n);
			else if (nbr > 0)
				ft_putnbr(nbr, base_len, base);
			length = length + n;
		}
		else
		{
			write(1, str, 1);
			length++;
		}
		str++;
	}
	va_end(args);
	return (length);
}

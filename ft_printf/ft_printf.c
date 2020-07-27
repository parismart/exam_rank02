/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:15:07 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/25 20:40:18 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	ft_nbrlen(long long n, int base_len)
{
	size_t	i;

	i = 1;
	while (n >= base_len)
	{
		n = n / base_len;
		i++;
	}
	return (i);
}

static void		ft_putnbr(long long nbr, int base_len, char *base)
{
	if (nbr >= base_len)
		ft_putnbr(nbr / base_len, base_len, base);
	write(1, &base[nbr % base_len], 1);
}

int		ft_printf(char *format, ...)
{
	va_list	valist;
	char	*str;
	char	*s;
	char	*base;
	long	nbr;
	int		base_len;
	int		neg;
	int		n;
	int		width;
	int		precision;
	int		flag_prec;
	int		spaces;
	int		zeros;
	int		length;

	neg = 0;
	n = 0;
	width = 0;
	precision = 0;
	flag_prec = 0;
	spaces = 0;
	zeros = 0;
	length = 0;
	va_start(valist, format);
	str = format;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			neg = 0;
			n = 0;
			width = 0;
			precision = 0;
			flag_prec = 0;
			spaces = 0;
			zeros = 0;
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + (*str - 48);
				str++;
			}
			if (*str == '.')
			{
				flag_prec = 1;
				str++;
				while (*str >= '0' && *str <= '9')
				{
					precision = precision * 10 + (*str - 48);
					str++;
				}
			}
			if (*str == 's')
			{
				s = va_arg(valist, char *);
				if (!s)
					s = "(null)";
				n = ft_strlen(s);
			}
			if (*str == 'd')
			{
				nbr = va_arg(valist, long);
				base_len = 10;
				base = "0123456789";
				if (nbr < 0)
				{
					nbr = -nbr;
					neg = 1;
				}
				n = ft_nbrlen(nbr, base_len) + neg;
			}
			if (*str == 'x')
			{
				nbr = va_arg(valist, unsigned);
				base_len = 16;
				base = "0123456789abcdef";
				n = ft_nbrlen(nbr, base_len);
			}
			if (flag_prec == 1 && precision > n && *str != 's')
				zeros = precision - n + neg;
			else if (flag_prec == 1 && precision < n && *str == 's')
				n = precision;
			else if (flag_prec == 1 && precision == 0 && (*str == 's' || nbr == 0))
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
			else if (n > 0)
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
	va_end(valist);
	return (length);
}

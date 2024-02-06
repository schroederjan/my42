/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:15:25 by jschroed          #+#    #+#             */
/*   Updated: 2024/02/05 19:42:51 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

// s

static int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

// d

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_putint(long long n)
{
	if (n < 0)
	{
		ft_printchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putint(n / 10);
	ft_printchar(n % 10 + '0');
}

static int	ft_printint(int n)
{
	int	count;

	if (n == 0)
		count = write(1, "0", 1);
	else
	{
		count = 0;
		ft_putint((long long)n);
		count += ft_intlen(n);
	}
	return (count);
}

// x

static int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_puthex(unsigned int num)
{
	if (num >= 16)
		ft_puthex(num / 16);
	num = num % 16;
	if (num <= 9)
		ft_printchar(num + '0');
	else
		ft_printchar(num - 10 + 'a');
}

static int	ft_printhex(unsigned int num)
{
	int	count;

	if (num == 0)
		count = write(1, "0", 1);
	else
	{
		count = 0;
		ft_puthex(num);
		count += ft_hexlen(num);
	}
	return (count);
}

// format, parser, printf

static int	ft_formats(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_printchar(va_arg(args, int));
	if (format == 's')
		count += ft_printstr(va_arg(args, char *));
	if (format == 'd')
		count += ft_printint(va_arg(args, int));
	if (format == 'x')
		count += ft_printhex(va_arg(args, unsigned int));
	return (count);
}

static int	ft_parser(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			count += ft_printchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_parser(format, args);
	va_end(args);
	return (count);
}

// main

int main(void)
{
	ft_printf("%s\n", "string");
	ft_printf("%c\n", 'c');
	ft_printf("%d\n", 666);
	ft_printf("%x\n", 255);
	ft_printf("nothing");
}

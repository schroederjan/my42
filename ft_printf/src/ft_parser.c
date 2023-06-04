/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:12:38 by jschroed          #+#    #+#             */
/*   Updated: 2023/06/04 18:19:27 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_printchar(va_arg(args, int));
	if (format == 's')
		count += ft_printstr(va_arg(args, char *));
	if (format == 'd' || format == 'i')
		count += ft_printnbr(va_arg(args, int));
	if (format == 'p')
		count += ft_printptr(va_arg(args, uintptr_t));
	if (format == 'u')
		count += ft_printunsigned(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		count += ft_printhex(va_arg(args, unsigned int), format);
	if (format == '%')
		count += ft_printpercent();
	return (count);
}

int	ft_parser(const char *format, va_list args)
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

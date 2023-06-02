/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:12:38 by jschroed          #+#    #+#             */
/*   Updated: 2023/06/02 08:19:51 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		count += ft_printstr(va_arg(args, char *)); // TODO why char *?
	if (format == 'd' || format == 'i')
		count += ft_printnbr(va_arg(args, int));
	if (format == 'p')
		count += ft_printptr(va_arg(args, uintptr_t));
	// TODO more
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

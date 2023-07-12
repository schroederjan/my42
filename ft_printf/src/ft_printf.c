/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:15:25 by jschroed          #+#    #+#             */
/*   Updated: 2023/07/12 18:45:24 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_parser(format, args);
	va_end(args);
	return (count);
}

/* [> [> TEMP <] <] */
/* int	main(void) */
/* { */
/*     char	c; */
/*     c = 'c'; */
/*     ft_printf("%c", c); */
/* } */

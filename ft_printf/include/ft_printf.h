/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:38:12 by jschroed          #+#    #+#             */
/*   Updated: 2023/06/04 18:27:45 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
// # include "../libft/libft.h"

// ------ PRINTF ------ //

int		ft_printf(const char *format, ...);
int		ft_parser(const char *format, va_list args);

// ------ SPECIFIERS ------ //

// c
int		ft_putchar(int c);
// s
int		ft_printstr(char *str);
void	ft_putstr(char *str);
// d || i
// int		ft_printnbr(int n);
int		ft_printint(int n);
// p
int		ft_printptr(uintptr_t ptr);
// u
int		ft_printunsigned(unsigned int num);
// x || X
int		ft_printhex(unsigned int num, const char format);
// %
int		ft_printpercent(void);

#endif

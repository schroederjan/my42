/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:38:12 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/31 19:05:38 by jschroed         ###   ########.fr       */
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
// int		ft_print_char(char c, t_flags flags);
// int		ft_print_c(char c);

#endif

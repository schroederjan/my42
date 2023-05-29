/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:38:12 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/29 11:23:58 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

// ------ FLAGS ------ //

typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

// ------ PRINTF ------ //

int		ft_printf(const char *format, ...);

// ------ SPECIFIERS ------ //

// c
int		ft_print_char(char c, t_flags flags);
int		ft_print_c(char c);

#endif

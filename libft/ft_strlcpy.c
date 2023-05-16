/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:40:33 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/04 18:52:06 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < size)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < size)
		*dst = 0;
	while (*src++)
		i++;
	return (i);
}

/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*  */
/*     char *src = "0123456789"; */
/*     char dest[10];  // use a large enough buffer */
/*     unsigned int size; */
/*     unsigned int result; */
/*  */
/*     size = 1; */
/*     printf( */
/*         "BEFORE\n\tsrc: %s\n\tdest: %s\n", */
/*         src, */
/*         dest */
/*     ); */
/*     while (size <= 10) */
/*     { */
/*         [> need to be reset before each call if not looped through <] */
/*         ft_strlcpy(dest, "", 1); */
/*         result = ft_strlcpy(dest, src, size); */
/*         printf( */
/*             "AFTER\n\tsrc: %s\n\tdest: %s\n\tsize: %d\n\tresult: %d\n", */
/*             src, */
/*             dest, */
/*             size, */
/*             result */
/*         ); */
/*         size++; */
/*     } */
/*  */
/*     return (0); */
/* } */

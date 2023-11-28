/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:48:17 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/05 21:09:27 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
		{
			return ((void *)p);
		}
		p++;
	}
	return (NULL);
}

/* #include <stdio.h> */
/* #include <string.h> */
/*  */
/* int	main(void) */
/* { */
/*     const char	*s = "he llo"; */
/*     int		c = 32; // search for the ' '  */
/*     size_t	n = strlen(s); */
/*     char	*result = ft_memchr(s, c, n); */
/*     char	*result_org = memchr(s, c, n); */
/*  */
/*     if (result) // if it is found return the pointer at current pos */
/*     { */
/*         printf("%s\n", result); */
/*         printf("%s\n", result_org); */
/*     } */
/*     else // if it is not fount return NULL */
/*     { */
/*         printf("%p\n", result); */
/*         printf("%p\n", result_org); */
/*     } */
/* } */

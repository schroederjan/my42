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

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}

/* #include <stdio.h> */
/* #include <string.h> */
/*  */
/* int	main(void) */
/* { */
/*     const char	*s = "Hello"; */
/*     int		c = 'T'; */
/*     size_t	n = 8; */
/*     char	*result = ft_memchr(s, c, n); */
/*     [> char	*result_org = memchr(s, c, n); <] */
/*  */
/*     printf("%s\n", result); */
/*     [> printf("%s\n", result_org); <] */
/*  */
/* } */

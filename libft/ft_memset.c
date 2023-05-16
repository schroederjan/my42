/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:15:05 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/05 08:31:11 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	void	*ret;

	ret = b;
	while (n--)
		*(char *)b++ = (unsigned char)c;
	return (ret);
}

// simple main to test
/* #include <stdio.h> */
/*  */
/* int	main(void) */
/* { */
/*     char	buf[] = "helllllooo"; */
/*     int		ic; */
/*     size_t	stn; */
/*  */
/*     ic = 'a'; // set a char to for the memory to be flushed with */
/*     stn = 3; // set the size of the flush */
/*  */
/*     ft_memset(buf, ic, stn); // flush the memory */
/*     [> buf[stn] = 0; // to add \0 at the end because we use %s to print <] */
/*  */
/*     printf("%s\n", buf); */
/* } */

/* more test for using malloc and not needing to add a \0 for printing */
/* int	main(void) */
/* { */
/*     char	*buf; */
/*     int		ic; */
/*     size_t	stn; */
/*  */
/*     ic = 'a'; // set a char to for the memory to be flushed with */
/*     stn = 3; // set the size of the flush */
/*  */
/*     buf = (char *)malloc(stn); */
/*     if (buf == NULL) */
/*     { */
/*         return 1; */
/*     } */
/*  */
/*     ft_memset(buf, ic, stn); // flush the memory */
/*     for (size_t i = 0; i < stn; i++) */
/*     { */
/*         printf("%c", buf[i]); */
/*     } */
/*     printf("\n"); */
/* } */

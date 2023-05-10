/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:01:02 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/10 09:33:50 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// needed here because of declaration conflict
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = malloc(sizeof(*ret) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

/* // temp for main only */
/* size_t	ft_strlen(char const *s) // char const are adapted to substring */
/* { */
/*     size_t	i; */
/*  */
/*     i = 0; */
/*     while (*s++) */
/*         i++; */
/*     return (i); */
/* } */
/*  */
/* size_t	ft_strlcpy(char *dest, char const *src, size_t size) */
/* { */
/*     size_t	i; */
/*  */
/*     i = 0; */
/*     while (*src && i + 1 < size) */
/*     { */
/*         *dest++ = *src++; */
/*         i++; */
/*     } */
/*     if (i < size) */
/*         *dest = 0; */
/*     while (*src++) */
/*         i++; */
/*     return (i); */
/* } */
/*  */
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     char const		*s = "hello and world"; */
/*     unsigned int	start = 6; */
/*     size_t			len = 3;	 */
/*     char			*sub; */
/*  */
/*     sub = ft_substr(s, start, len); */
/*  */
/*     if (sub != NULL) */
/*     { */
/*         printf("%s\n", sub); */
/*         free(sub); */
/*  */
/*     } */
/*     else */
/*     { */
/*         printf("Substring operation failed.\n"); */
/*     } */
/*     return (0); */
/* } */

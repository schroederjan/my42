/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:33:13 by jschroed          #+#    #+#             */
/*   Updated: 2023/07/04 20:38:46 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (s + i);
		i++;
	}
	return (0);
}

/* [> Temp <] */
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     printf("%zu", ft_strlen("abc")); */
/*     printf("\n"); */
/*     printf("%c", *ft_strchr("abc", 'b')); */
/*     printf("\n"); */
/* } */

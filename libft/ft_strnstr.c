/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:02:43 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/08 21:20:47 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_temp;
	char	*little_temp;
	size_t	i;

	if (!ft_strlen(little))
		return ((char *)big);
	if (!ft_strlen(big) || len < ft_strlen(little))
		return (0);
	i = len - ft_strlen(little) + 1;
	while (i-- && *big)
	{
		big_temp = (char *)big;
		little_temp = (char *)little;
		while (*little_temp && *little_temp == *big_temp)
		{
			little_temp++;
			big_temp++;
		}
		if (!*little_temp)
			return ((char *)big);
		big++;
	}	
	return (0);
}

/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     const char *big = "hi this is a test"; */
/*     const char *little = "is a test"; */
/*     size_t len = 10; */
/*  */
/*     printf("%s\n", ft_strnstr(big, little, len)); */
/* }	 */
/*  */
/* // TODO */
/* size_t	ft_strlen(const char *s) */
/* { */
/*     size_t	i; */
/*  */
/*     i = 0; */
/*     while (*s++) */
/*         i++; */
/*     return (i); */
/* } */

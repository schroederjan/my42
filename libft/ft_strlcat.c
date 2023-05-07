/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:30:13 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/07 16:43:23 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (*dest && i < size)
	{
		dest++;
		i++;
	}
	ret = ft_strlcpy(dest, src, size - i);
	return (ret + i);
}

/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     char	dest[6] = "abc"; */
/*     char	*src = "123"; */
/*     size_t size = 6; */
/*  */
/*     printf("return: %s, dest: %s\n", ft_strlcat(dest, src, size), dest); */
/* } */

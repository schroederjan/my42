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

char	*ft_strjoin(char *rest_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!rest_str)
	{
		rest_str = (char *)malloc(1 * sizeof(char));
		rest_str[0] = '\0';
	}
	if (!rest_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(rest_str) + ft_strlen(buff)) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (rest_str)
		while (rest_str[++i] != '\0')
			str[i] = rest_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(rest_str) + ft_strlen(buff)] = '\0';
	free(rest_str);
	return (str);
}

char	*ft_get_line(char *rest_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest_str[i])
		return (NULL);
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	if (rest_str[i] == '\n')
	{
		str[i] = rest_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_update_rest_str(char *rest_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rest_str[i] && rest_str[i] != '\n')
		i++;
	if (!rest_str[i]) //TODO check why?
	{
		free(rest_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest_str) - i + 1)); //TODO do i need sizeof char?
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rest_str[i])
		str[j++] = rest_str[i++];
	str[j] = '\0';
	free(rest_str);
	return (str);
}

// TODO make test for main ft_get_more
// TODO make test for main ft_get_line

/* [> Temp <] */
/* #include <stdio.h> */
/* #include <string.h> */
/* int	main(void) */
/* { */
/*     printf("%zu", ft_strlen("abc")); */
/*     printf("\n"); */
/*     printf("%c", *ft_strchr("abc", 'b')); */
/*     printf("\n"); */
/*     char *rest_str = strdup("abc"); */
/*     char *buff = "def"; */
/*     char *result = ft_strjoin(rest_str, buff); */
/*     printf("%s", result); */
/* } */

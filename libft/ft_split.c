/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:15:39 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/11 19:21:54 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// aa bb cc -> 3 words

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*make_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;

	i = 0;
	if (!s)
		return (0);
	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words[i] = make_word(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	words[i] = 0;
	return (words);
}

/* // temp only */
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     char const *s = "aa bb cc"; */
/*     char		c = ' '; */
/*     char		**split; */
/*     int			i = 0; */
/*  */
/*     split = ft_split(s, c); */
/*     while (split[i]) */
/*     { */
/*         printf("%s\n", split[i]); */
/*         free(split[i]);  // Free each string */
/*         i++; */
/*     } */
/*     return (0); */
/* } */

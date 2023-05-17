/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:26:51 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/17 18:16:48 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = 0;
	return (ret);
}

/* // temp for main */
/* #include <stdio.h> */
/* #include <string.h> */
/* int	main(void) */
/* { */
/*     // content is int */
/*     int	*p = malloc(sizeof(int)); */
/*     if (!p) */
/*         return (1); */
/*     *p = 42; */
/*     t_list *node = ft_lstnew(p); */
/*     if (!node) */
/*     { */
/*         free(p); */
/*         return (1); */
/*     } */
/*     printf("%d\n", *(int *)(node->content)); */
/*     free(node->content); */
/*     free(node); */
/*  */
/*     // content is str */
/*     char *s = malloc(sizeof(char) * 6); */
/*     if (!s) */
/*         return 1; */
/*     strcpy(s,"Hello"); */
/*     t_list *node_str = ft_lstnew(s); */
/*     if (!node_str) */
/*     { */
/*         free(s); */
/*         return 1; */
/*     } */
/*     printf("%s\n", (char *)(node_str->content)); */
/*     free(node_str->content); */
/*     free(node_str); */
/*  */
/*     return (0); */
/* } */
/*  */

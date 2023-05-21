/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:39:32 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/21 14:24:07 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* // temp for main */
/* t_list	*ft_lstnew(void	*content) */
/* { */
/*     t_list	*ret; */
/*     ret = malloc(sizeof(t_list)); */
/*     if (!ret) */
/*         return (NULL); */
/*     ret->content = content; */
/*     ret->next = NULL; */
/*     return (ret); */
/* } */
/*  */
/* void	ft_lstadd_front(t_list **lst, t_list *new) */
/* { */
/*     if (lst && new) */
/*     { */
/*         new->next = *lst; */
/*         *lst = new; */
/*     } */
/* } */
/*  */
/* #include <stdio.h> */
/* #include <string.h> */
/* void	apply(void *content) */
/* { */
/*     printf("PRINT APPLY: %s\n", (char *)content); */
/* } */
/*  */
/* int	main(void) */
/* { */
/*     t_list	*head = NULL; */
/*     t_list	*node = ft_lstnew("abc"); */
/*  */
/*     ft_lstadd_front(&head, node); */
/*  */
/*     printf("%s\n", (char *)node->content); */
/*     ft_lstiter(node, apply); */
/*     printf("%s\n", (char *)node->content); */
/* } */

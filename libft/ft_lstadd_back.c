/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:07:11 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/18 14:36:04 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*(lst));
			tmp->next = new;
		}
	}
}

/* // temp for main */
/* t_list	*ft_lstnew(void *content) */
/* { */
/*     t_list	*ret; */
/*      */
/*     ret = malloc(sizeof(t_list)); */
/*     if (!ret) */
/*         return (NULL); */
/*     ret->content = content; */
/*     ret->next = NULL; */
/*     return (ret); */
/* } */
/*  */
/* t_list	*ft_lstlast(t_list *lst) */
/* { */
/*     t_list	*tmp; */
/*  */
/*     tmp = lst; */
/*     if (lst) */
/*         while (tmp->next) */
/*             tmp = tmp->next; */
/*     return (tmp); */
/* } */
/*  */
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     t_list	*head = NULL; */
/*     t_list	*node1; */
/*     t_list	*node2; */
/*  */
/*     node1 = ft_lstnew("a"); */
/*     node2 = ft_lstnew("b"); */
/*  */
/*     ft_lstadd_back(&head, node1); */
/*     ft_lstadd_back(&head, node2); */
/*  */
/*     // print whole list */
/*     while (head) */
/*     { */
/*         printf("%s\n", (char *)head->content); */
/*         head = head->next; */
/*     } */
/* } */

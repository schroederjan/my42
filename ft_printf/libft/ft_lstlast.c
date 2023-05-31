/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:48:23 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/18 13:48:23 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (lst)
		while (current->next)
			current = current->next;
	return (current);
}

/* // temp for main */
/* t_list	*ft_lstnew(void *content) */
/* { */
/*     t_list	*ret; */
/*  */
/*     ret = malloc(sizeof(t_list)); */
/*     if (!ret) */
/*         return (0); */
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
/* int	main(void) */
/* { */
/*     t_list	*current; */
/*     t_list	*head = NULL; */
/*     t_list	*node1 = ft_lstnew("content1"); */
/*     t_list	*node2 = ft_lstnew("content2"); */
/*  */
/*     ft_lstadd_front(&head, node2); */
/*     ft_lstadd_front(&head, node1); */
/*  */
/*     current = ft_lstlast(head); */
/*     printf("%s\n", (char *)current->content); */
/* } */

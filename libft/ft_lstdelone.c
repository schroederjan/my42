/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:40:45 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/19 20:48:31 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* // temp for main */
/* t_list	*ft_lstnew(void *content) */
/* { */
/*     t_list	*ret; */
/*  */
/*     ret = malloc(sizeof(t_list)); */
/*     if (!ret) */
/*         return (NULL); */
/*     ret->content = content; */
/*     ret->next = NULL; */
/*     return (ret); */
/* } */
/*  */
/* void	ft_lstadd_back(t_list **lst, t_list *new) */
/* { */
/*     t_list	*current; */
/*  */
/*     if (lst) */
/*     { */
/*         if (*lst == NULL) */
/*             *lst = new; */
/*         else */
/*         { */
/*             current = ft_lstlast(*lst); */
/*             current->next = new; */
/*         } */
/*     } */
/* } */
/*  */
/* t_list	*ft_lstlast(t_list *lst) */
/* { */
/*     t_list	*current; */
/*  */
/*     current = lst; */
/*     while (current->next) */
/*         current = current->next; */
/*     return (current); */
/* } */
/*  */
/* int	ft_lstsize(t_list *lst) */
/* { */
/*     t_list	*current; */
/*     int		count; */
/*  */
/*     count = 0; */
/*     current = lst; */
/*     while (current) */
/*     { */
/*         current = current->next; */
/*         count++; */
/*     } */
/*     return (count); */
/* } */
/*  */
/* void	delete_content(void *content) */
/* { */
/*     free(content); */
/* } */
/*  */
/* #include <stdio.h> */
/* #include <string.h> */
/* int	main(void) */
/* { */
/*     t_list *head = 0; */
/*     char *dynamic_content = malloc(100 * sizeof(char)); */
/*     // Imagine this is filled with meaningful data */
/*     strcpy(dynamic_content,"abc"); */
/*     t_list *node = ft_lstnew(dynamic_content); */
/*  */
/*     ft_lstadd_back(&head, node); */
/*     printf("%s\n", (char *)node->content); */
/*  */
/*     ft_lstdelone(node, delete_content); */
/*     printf("content and node has been freed, nothing to print"); */
/* } */

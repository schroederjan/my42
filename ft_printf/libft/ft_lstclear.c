/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:03:39 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/20 12:03:50 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		del(current->content);
		free(current);
		current = temp;
	}
	*lst = NULL;
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
/*     }	 */
/* } */
/*  */
/* t_list	*ft_lstlast(t_list	*lst) */
/* { */
/*     t_list	*current; */
/*  */
/*     current = lst; */
/*     while (current) */
/*         current = current->next; */
/*     return (current); */
/* } */
/*  */
/* void	del(void *content) */
/* { */
/*     free(content); */
/* } */
/*  */
/* #include <stdio.h> */
/* int	main(void) */
/* { */
/*     t_list	*head = NULL; */
/*     t_list	*node; */
/*  */
/*     // creation */
/*     // Allocate space for 2 chars */
/*     char *str = malloc(2 * sizeof(char));  */
/*     if (str) {  // Always check if malloc succeeded */
/*         str[0] = 'a'; */
/*         str[1] = '\0'; */
/*     } */
/*     node = ft_lstnew(str); */
/*     ft_lstadd_back(&head, node); */
/*     printf("%s\n", (char *)node->content); */
/*     printf("%p\n", node); */
/*  */
/*     //deletion */
/*     ft_lstclear(&head, del); */
/*     node = NULL; */
/*     printf("%p\n", node); */
/* } */

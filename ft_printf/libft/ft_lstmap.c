/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:49:58 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/21 15:35:36 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this lstmap will take care of using malloc inside the f()
#include "libft.h"

t_list	*new_node(void *(*f)(void *), void *content, void (*del)(void *))
{
	void	*new_content;
	t_list	*new;

	new_content = f(content);
	new = ft_lstnew(new_content);
	if (!new)
		del(new_content);
	return (new);
}

t_list	*add_to_list(t_list **head, t_list *new, void (*del)(void *))
{
	if (!new)
	{
		ft_lstclear(head, del);
		return (NULL);
	}
	ft_lstadd_back(head, new);
	return (*head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (!lst)
		return (NULL);
	head = new_node(f, lst->content, del);
	if (!head)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = new_node(f, lst->content, del);
		if (!add_to_list(&head, new, del))
			return (NULL);
		lst = lst->next;
	}
	return (head);
}

/* // temp for main */
/* #include <stdio.h> */
/* t_list	*ft_lstnew(void *content) */
/* { */
/*     t_list *ret; */
/*  */
/*     ret = malloc(sizeof(t_list)); */
/*     if (!ret) */
/*         return (NULL); */
/*     ret->content = content; */
/*     ret->next = NULL; */
/*     return (ret); */
/* } */
/*  */
/* void	delete_content(void *content) */
/* { */
/*     free(content); */
/* } */
/*  */
/* void	*print_content(void *content) */
/* { */
/*     printf("%s\n", (char *)content); */
/*     return (content); */
/* } */
/*  */
/* void	ft_lstclear(t_list **lst, void (*del)(void *)) */
/* { */
/*  */
/*     t_list	*current; */
/*     t_list	*temp; */
/*  */
/*     if (!lst || !del) */
/*         return ; */
/*     current = *lst; */
/*     while (current) */
/*     { */
/*         temp = current->next; */
/*         del(current->content); */
/*         free(current); */
/*         current = temp; */
/*     } */
/*     *lst = NULL; */
/* } */
/*  */
/* t_list	*ft_lstlast(t_list *lst) */
/* { */
/*     t_list	*current; */
/*  */
/*     current = lst; */
/*     if (lst) */
/*         while (current->next) */
/*             current = current->next; */
/*     return (current); */
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
/* int	main(void) */
/* { */
/*     t_list	*head = NULL; */
/*     t_list	*node1; */
/*     t_list	*node2; */
/*     t_list	*node3; */
/*  */
/*     node1 = ft_lstnew("a"); */
/*     node2 = ft_lstnew("b"); */
/*     node3 = ft_lstnew("c"); */
/*  */
/*     ft_lstadd_back(&head, node1); */
/*     ft_lstadd_back(&head, node2); */
/*     ft_lstadd_back(&head, node3); */
/*  */
/*     printf("\nHEAD: \n"); */
/*     t_list	*temp; */
/*     temp = head; */
/*     while (temp) */
/*     { */
/*         printf("%s\n", (char *)temp->content); */
/*         temp = temp->next; */
/*     } */
/*     printf("\n"); */
/*  */
/*     printf("MAP: \n"); */
/*     t_list	*new_head; */
/*     new_head = ft_lstmap(head, print_content, delete_content); */
/*     printf("\n"); */
/*  */
/*     printf("NEW HEAD: \n"); */
/*     t_list	*new_temp; */
/*     new_temp = new_head; */
/*     while (new_temp) */
/*     { */
/*         printf("%s\n", (char *)new_temp->content); */
/*         new_temp = new_temp->next; */
/*     } */
/*     printf("\n"); */
/* } */

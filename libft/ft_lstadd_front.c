/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:42:32 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/17 19:04:01 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// temp for main
#include <stdio.h>
t_list *ft_lstnew(void *content)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node)
	{
		node->content = content;
		node->next = NULL;
	}
	return (node);
}

int main()
{
	t_list *head = NULL;
	t_list *node1 = ft_lstnew("a");
	t_list *node2 = ft_lstnew("b");

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);

	t_list *temp = head;
	while (temp != NULL)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}

	return 0;
}

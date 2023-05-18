/*usr/bin/cc -Wall -Wextra -Werror -g "$0" && exec ./a.out "$@"*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:28:21 by jschroed          #+#    #+#             */
/*   Updated: 2023/05/18 13:45:13 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	count = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
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
/*     ret->next = 0; */
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
/*     t_list	*head = ft_lstnew(0); */
/*     t_list	*node_1 = ft_lstnew("node1"); */
/*     t_list	*node_2 = ft_lstnew("node2"); */
/*  */
/*     ft_lstadd_front(&head, node_1); */
/*     ft_lstadd_front(&head, node_2); */
/*  */
/*     printf("%d\n", ft_lstsize(head)); */
/* } */

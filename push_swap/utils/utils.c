/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:16:18 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/19 19:10:36 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handler(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (*str)
		i++;
	while (i >= 0)
		free(str[i--]);
}

int		is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

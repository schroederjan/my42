/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:16:18 by jschroed          #+#    #+#             */
/*   Updated: 2023/11/17 09:13:35 by jschroed         ###   ########.fr       */
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

int	is_sorted(t_list **stack)
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

// use triple pointer to save lines in main
// otherwise need to free pointer to stack itself
void	free_stack(t_list ***stack)
{
	t_list	*current;
	t_list	*next;

	if (stack && *stack)
	{
		current = **stack;
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(*stack);
		*stack = NULL;
	}
}

int	smallest_index_position(t_list **stack, int index)
{
	t_list	*head;
	int		position_from_top;

	position_from_top = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		position_from_top++;
		head = head->next;
	}
	return (position_from_top);
}

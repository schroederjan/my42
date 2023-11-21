/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:55:48 by jschroed          #+#    #+#             */
/*   Updated: 2023/11/21 17:44:37 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		min_found;

	min = NULL;
	min_found = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!min_found || head->value < min->value))
			{
				min = head;
				min_found = 1;
			}
			head = head->next;
		}
	}

	// Debugging print statement
    if (min) {
        printf("Next minimum found: Value = %d, Index = %d\n", min->value, min->index);
    } else {
        printf("No next minimum found.\n");
    }

	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		printf("Assigning Index: %d to Value: %d\n", head->index, head->value); // Debug print
		head = get_next_min(stack);
	}
}

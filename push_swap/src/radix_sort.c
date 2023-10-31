/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:41:34 by jschroed          #+#    #+#             */
/*   Updated: 2023/10/31 10:52:55 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// getting how many bits the max_index has eg. 13 => 1101 => 4 bits
static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max_index;
	int		max_bits;

	head = *stack;
	max_index = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max_index)
			max_index = head->index;
		head = head->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		bit_pos;
	int		j;
	int		size;
	int		max_bits;

	bit_pos = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (bit_pos < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> bit_pos) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		bit_pos++;
	}
}

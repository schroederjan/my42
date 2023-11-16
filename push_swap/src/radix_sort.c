/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:41:34 by jschroed          #+#    #+#             */
/*   Updated: 2023/11/16 10:21:08 by jschroed         ###   ########.fr       */
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

/* EXAMPLE: */

/* Sorted: 1, 2, 3, 4, 5, 6 */
/* Original: 5, 1, 6, 3, 2, 4 */
/* Indices: 4, 0, 5, 2, 1, 3 */

/* 4 in binary: 100 */
/* 0 in binary: 000 */
/* 5 in binary: 101 */
/* 2 in binary: 010 */
/* 1 in binary: 001 */
/* 3 in binary: 011 */

/* 4 (100): LSB is 0 → Push to stack_b (pb). */
/* 0 (000): LSB is 0 → Push to stack_b. (pb)*/
/* 5 (101): LSB is 1 → Rotate (ra). */
/* 2 (010): LSB is 0 → Push to stack_b. (pb)*/
/* 1 (001): LSB is 1 → Rotate. (ra)*/
/* 3 (011): LSB is 1 → Rotate. (ra)*/

// NOTE: issues from here

/* stack_a: [1, 3, 5] */
/* stack_b: [2, 0, 4] (top to bottom) */

/* stack_a: [4, 0, 2, 1, 3, 5] */

/* 4 (100): Second bit is 0 → Push to stack_b. (pb)*/
/* 0 (000): Second bit is 0 → Push to stack_b. (pb)*/
/* 2 (010): Second bit is 1 → Rotate. (ra)*/
/* 1 (001): Second bit is 0 → Push to stack_b. (pb)*/
/* 3 (011): Second bit is 1 → Rotate. (ra)*/
/* 5 (101): Second bit is 0 → Push to stack_b. (pb)*/

/* stack_a: [3, 2] */
/* stack_b: [5, 1, 0, 4] */

/* stack_a: [4, 0, 1, 5, 3, 2] */

/* 4 (100): Third bit is 1 → Rotate. (ra)*/
/* 0 (000): Third bit is 0 → Push to stack_b. (pb)*/
/* 1 (001): Third bit is 0 → Push to stack_b. (pb)*/
/* 5 (101): Third bit is 1 → Rotate. (ra)*/
/* 3 (011): Third bit is 0 → Push to stack_b. (pb)*/
/* 2 (010): Third bit is 0 → Push to stack_b. (pb)*/

/* stack_a: [5, 4] */
/* stack_b: [2, 3, 1, 0] */

/* stack_a: [0, 1, 3, 2, 5, 4] */

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

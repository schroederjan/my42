/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:28:31 by jschroed          #+#    #+#             */
/*   Updated: 2023/11/17 09:18:53 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

// Examples:
//
// ra, sa, rra
// init: 1,3,2
// result: 3,2,1
// result: 2,3,1
// result: 1,2,3
//
// sa
// init: 2,1,3
// result: 1,2,3
//
// rra
// init: 2,3,1
// result: 1,2,3
//
// ra
// init: 3,1,2
// result: 1,2,3
//
// sa, rra
// init: 3,2,1
// result: 2,3,1
// result: 1,2,3

static void	sort_3(t_list **stack_a)
{
	int	idx1;
	int	idx2;
	int	idx3;

	if (is_sorted(stack_a))
		return ;
	idx1 = (*stack_a)->index;
	idx2 = (*stack_a)->next->index;
	idx3 = (*stack_a)->next->next->index;
	if (idx1 > idx2 && idx2 < idx3 && idx3 > idx1)
		sa(stack_a);
	else if (idx1 > idx2 && idx2 > idx3)
		sa_rra(stack_a);
	else if (idx1 > idx2)
		ra(stack_a);
	else if (idx2 > idx3)
		sa_ra(stack_a);
	else
		rra(stack_a);
}

// pos is 0,1,2,3...n
// bring smallest index to top
// if on top then pb
// then sort stack_a
// then pb
static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	smallest_index_at;

	if (is_sorted(stack_a))
		return ;
	smallest_index_at = smallest_index_position(stack_a, get_min(stack_a, -1));
	if (smallest_index_at == 1)
		ra(stack_a);
	else if (smallest_index_at == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (smallest_index_at == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

// logic same as sort_4
static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	smallest_index_at;

	smallest_index_at = smallest_index_position(stack_a, get_min(stack_a, -1));
	if (smallest_index_at == 1)
		ra(stack_a);
	else if (smallest_index_at == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (smallest_index_at == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (smallest_index_at == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	(void )stack_b;
	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

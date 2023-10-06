/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:28:31 by jschroed          #+#    #+#             */
/*   Updated: 2023/10/06 21:13:52 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* TODO: Implement sort functions above */

static int	get_min(t_list **stack, int val)
{
	t_list *head;
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

static void	sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	// TODO: continue
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
	/*     s3; */
	/* else if (size == 4) */
	/*     s4; */
	/* else if (size == 5) */
	/*     s5; */
}


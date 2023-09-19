/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:28:31 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/19 19:51:54 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* TODO: Implement sort functions above */

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
	/* else if (size == 3) */
	/*     s3; */
	/* else if (size == 4) */
	/*     s4; */
	/* else if (size == 5) */
	/*     s5; */
}


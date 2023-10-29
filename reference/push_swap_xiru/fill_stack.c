/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:47:32 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/10 19:18:53 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack *fill_stack_value(char **av);

t_stack	*fill_stack(char **av)
{
	t_stack	*a;

	a = fill_stack_value(av);
	if (is_sorted(a) == 1)
	{
		free_stack(&a);
		exit(1);//display nothing
	}
	return (a);
}

static t_stack	*fill_stack_value(char **av)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;
	int		value;

	i = 1;
	value = 0;
	a = NULL;
	while(av[i])
	{
		value = atoi_range(av[i]);
		temp = new_node(value);
		node_add_back(&a, temp);
		i++;
	}
	return (a);
}

//check if stack is sorted.
int	is_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);//false
		a = a->next;
	}
	return (1);//true
}

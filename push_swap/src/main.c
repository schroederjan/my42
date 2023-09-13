/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:51:02 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/13 20:18:18 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list		*new_list;
	char		**args;
	int			i;

	i = 0;
	args = get_args(argc, argv, &i);
	while (args[i])
	{
		new_list = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new_list);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		free_tab(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (!stack_a)
		return (1);
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_b)
		return (1);
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	/* TODO: the rest here */
	return (0);
}

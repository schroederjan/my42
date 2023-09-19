/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:46:01 by jschroed          #+#    #+#             */
/*   Updated: 2023/09/19 19:56:34 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

// NOTE: not the t_list/s_list in libft
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

// util functions
void	error_handler(char *str);
void	free_tab(char **str);
void	check_args(int argc, char **argv);
char	**get_args(int argc, char **argv, int *start_index);
void	index_stack(t_list **stack);
int		is_sorted(t_list **stack);
void	free_stack(t_list **stack);

// linked_list functions
t_list	*ft_lstnew(int value);	
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new_node);
void	ft_lstadd_back(t_list **stack, t_list *new_node);
int		ft_lstsize(t_list *head);
// void	print_list(t_list *head);

// sort functions
void	simple_sort(t_list **stack_a, t_list **stack_b);

// operation functions
int		swap(t_list **stack_a);
int		sa(t_list **stack_a);

#endif

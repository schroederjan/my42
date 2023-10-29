/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:41:34 by jschroed          #+#    #+#             */
/*   Updated: 2023/10/29 21:42:10 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Helper function to get the bit at a specific position
static int get_bit_at_position(int number, int position) {
    return (number >> position) & 1;
}

// Find the maximum number in stack_a
static int find_max(t_list *stack) {
    int max_val = INT_MIN;

    while (stack) {
        if (stack->value > max_val) {
            max_val = stack->value;
        }
        stack = stack->next;
    }

    return max_val;
}

// Calculate the number of bits required to represent a number
static int calculate_bits(int number) {
    int bits = 0;

    while (number) {
        bits++;
        number >>= 1;
    }

    return bits;
}

void radix_sort(t_list **stack_a, t_list **stack_b) {
    int max_num = find_max(*stack_a);
    int max_bits = calculate_bits(max_num);

    for (int position = 0; position < max_bits; position++) {
        int size = ft_lstsize(*stack_a);

        for (int i = 0; i < size; i++) {
            if (get_bit_at_position((*stack_a)->value, position) == 0) {
                pb(stack_a, stack_b);  // Push to stack_b
            } else {
                ra(stack_a);  // Rotate stack_a
            }
        }

        // Move numbers back from stack_b to stack_a
        size = ft_lstsize(*stack_b);
        for (int i = 0; i < size; i++) {
            pa(stack_a, stack_b);  // Push to stack_a
        }
    }
}


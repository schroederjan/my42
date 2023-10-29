/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:59:30 by jschroed          #+#    #+#             */
/*   Updated: 2023/10/29 21:48:44 by jschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void bubble_sort(int arr[], int n) 
{
    int swapped = 1; // used to detect if any swapping happened in the loop
    int i = 0;
    int temp;

    while (swapped) 
    {
        swapped = 0;
        i = 0;

        while (i < n - 1) 
        {
            if (arr[i] > arr[i + 1]) 
            {
                // Swap the elements
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                swapped = 1;
            }
            i++;
        }

        n--; // Each iteration ensures the largest element (in the unsorted portion) bubbles up to its correct position
    }
}

static int get_percentile_value(t_list **stack_a, int percentile)
{
    int *values;
    int size;
    int nth_value;
	int i;
    t_list *head = *stack_a;

	i = 0;
    size = ft_lstsize(*stack_a);
    values = (int *)malloc(sizeof(int) * size);

    // Populate values array from the stack.
	while (head)
    {
        values[i] = head->value;
        head = head->next;
		i++;
    }

    // Use any sorting algorithm. Assuming a bubble sort here for simplicity.
	bubble_sort(values, i);

    nth_value = values[(size * percentile) / 100];
    free(values);
    return nth_value;
}

static void push_chunk_to_b(t_list **stack_a, t_list **stack_b, int max_value)
{
    int size = ft_lstsize(*stack_a);
    for (int i = 0; i < size; i++)
    {
        if ((*stack_a)->value <= max_value)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
    }
}

static void sort_using_chunks(t_list **stack_a, t_list **stack_b)
{
	int i;
    int chunk_size_percent = 20;  // We'll take chunks of 20% of the list.
    int num_chunks = 100 / chunk_size_percent;
    int max_value;

	i = 0;
	while (i < num_chunks)
    {
		max_value = get_percentile_value(stack_a, (i + 1) * chunk_size_percent);
        push_chunk_to_b(stack_a, stack_b, max_value);
		i++;

        // Sort this chunk back into stack_a using your existing logic.
        while (ft_lstsize(*stack_b))
        {
			if (ft_lstsize(*stack_a) <= 5)
				simple_sort(stack_a, stack_b);
			else
				radix_sort(stack_a, stack_b);
        }
    }
}

void complex_sort(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_a);
    if (size <= 5)
    {
        simple_sort(stack_a, stack_b);
        return;
    }
    sort_using_chunks(stack_a, stack_b);
}

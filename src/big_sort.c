/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 12:19:18 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/25 10:21:33 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	bit;
	int	size;

	bit = 0;
	while (!is_stack_sorted(*stack_a))
	{
		size = stack_size(*stack_a);
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->top->index >> bit) & 1)
				ra(*stack_a);
			else
				pb(*stack_a, *stack_b);
			i++;
		}
		while (stack_size(*stack_b) > 0)
			pa(*stack_a, *stack_b);
		bit++;
	}
}

int	bubblesort(t_stack *stack)
{
	t_node	*tmp;
	int		swapped;
	int		temp;

	if (!stack || !stack->top)
		return (1);
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		tmp = stack->top;
		while (tmp->next)
		{
			if (tmp->num > tmp->next->num)
			{
				temp = tmp->num;
				tmp->num = tmp->next->num;
				tmp->next->num = temp;
				swapped = 1;
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

/* returns 1 if error, 0 for success 
makes a table of indices of the sorted and unsorted stack and calls radix sort
*/
int	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack			*sorted_stack;
	t_hash_table	*mapping_table;

	sorted_stack = stack_copy(*stack_a);
	if (sorted_stack == NULL)
		return (1);
	if (bubblesort(sorted_stack) != 0)
	{
		stack_free(&sorted_stack);
		return (1);
	}
	mapping_table = create_mapping_table(sorted_stack);
	if (map_values_to_indices(*stack_a, mapping_table) == 1)
	{
		stack_free(&sorted_stack);
		return (1);
	}
	stack_free(&sorted_stack);
	radix_sort(stack_a, stack_b);
	return (0);
}

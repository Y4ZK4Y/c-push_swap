/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_engine.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/01 12:18:07 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/24 13:16:03 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	return_status;

	return_status = 0;
	size = stack_size(stack_a);
	if (size == 2 && !is_stack_sorted(stack_a))
		sa(stack_a);
	else if (size == 3)
		small_sort(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
	{
		return_status = big_sort(&stack_a, &stack_b);
		if (return_status == 1)
			return (1);
	}
	return (0);
}

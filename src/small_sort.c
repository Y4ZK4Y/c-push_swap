/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/23 14:59:08 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/25 10:21:25 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorts 3 numbers */
void	small_sort(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->num;
	second = stack->top->next->num;
	third = stack->top->next->next->num;
	if (first > second && second < third && third > first)
		sa(stack);
	else if (first > second && second > third && first > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (third < second && first < second && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && third < first)
		rra(stack);
}

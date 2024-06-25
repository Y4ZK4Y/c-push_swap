/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 17:05:07 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/25 10:24:03 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *stack)
{
	t_node	*node;
	int		min;

	if (stack->top == NULL)
		return (INT_MAX);
	node = stack->top;
	min = node->num;
	while (node != NULL)
	{
		if (node->num < min)
			min = node->num;
		node = node->next;
	}
	return (min);
}

static void	ra_or_rra(t_stack *stack, int position)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(stack);
	if (position <= size / 2)
	{
		while (i < position)
		{
			ra(stack);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - position)
		{
			rra(stack);
			i++;
		}
	}
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_min(stack_a);
	while (stack_peek(stack_a) != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	small_sort(stack_a);
	while (!is_stack_empty(stack_b))
		pa(stack_a, stack_b);
}

static int	find_position(t_stack *stack, int target)
{
	t_node	*node;
	int		position;

	if (stack->top == NULL)
		return (-1);
	node = stack->top;
	position = 0;
	while (node != NULL)
	{
		if (node->num == target)
			return (position);
		node = node->next;
		position++;
	}
	return (-1);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min_1;
	int	min_2;
	int	pos_1;
	int	pos_2;

	min_1 = find_min(stack_a);
	pos_1 = find_position(stack_a, min_1);
	ra_or_rra(stack_a, pos_1);
	pb(stack_a, stack_b);
	min_2 = find_min(stack_a);
	pos_2 = find_position(stack_a, min_2);
	ra_or_rra(stack_a, pos_2);
	pb(stack_a, stack_b);
	small_sort(stack_a);
	while (!is_stack_empty(stack_b))
		pa(stack_a, stack_b);
}

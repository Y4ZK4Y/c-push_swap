/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_ops.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:46:19 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/25 10:26:55 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes a node on top of the stack */
void	stack_push(t_stack *stack, t_node *node)
{
	node->next = stack->top;
	stack->top = node;
}

/* Removes the top node from the stack and returns its value */
int	stack_pop(t_stack *stack)
{
	t_node	*temp;
	int		num;

	if (is_stack_empty(stack))
		return (INT_MIN);
	temp = stack->top;
	num = temp->num;
	stack->top = temp->next;
	return (num);
}

/* Dreturns the top node of the stack if it's not empty */
int	stack_peek(t_stack *stack)
{
	if (is_stack_empty(stack))
		return (INT_MIN);
	else
		return (stack->top->num);
}

/* returns true if stack is sorted */
bool	is_stack_sorted(t_stack *stack)
{
	t_node	*temp;

	if (stack == NULL || stack->top == NULL)
		return (true);
	temp = stack->top;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->num > temp->next->num)
			return (false);
		temp = temp->next;
	}
	return (true);
}

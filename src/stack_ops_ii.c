/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_ops_ii.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/01 12:28:50 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/25 10:21:23 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swaps the top two nodes of the stack */
void	stack_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack_size(stack) < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

/* pushes the top node of stack a to the top of stack b */
void	stack_push_to(t_stack **from, t_stack **to)
{
	t_node	*node;

	if (is_stack_empty(*from))
		return ;
	node = (*from)->top;
	(*from)->top = (*from)->top->next;
	stack_push(*to, node);
}

/* top of the stack is sent to the bottom */
void	stack_rotate(t_stack *stack)
{
	t_node	*top;
	t_node	*last;

	if (stack_size(stack) < 2)
		return ;
	top = stack->top;
	last = stack->top;
	stack->top = top->next;
	while (last->next != NULL)
		last = last->next;
	last->next = top;
	top->next = NULL;
}

/* sends the bottom node to the top */
void	stack_reverse_rotate(t_stack *stack)
{
	t_node	*second_to_last;
	t_node	*last;

	if (stack_size(stack) < 2)
		return ;
	second_to_last = stack->top;
	last = NULL;
	while (second_to_last->next->next != NULL)
		second_to_last = second_to_last->next;
	last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

/* Creates a copy of the stack */
t_stack	*stack_copy(const t_stack *original_stack)
{
	t_stack	*new_stack;
	t_node	*new_node;
	t_node	*original_stack_top;

	if (original_stack == NULL)
		return (NULL);
	new_stack = create_stack();
	stack_init(new_stack);
	original_stack_top = original_stack->top;
	while (original_stack_top != NULL)
	{
		new_node = create_new_node(original_stack_top->num);
		if (new_node == NULL)
		{
			stack_free(&new_stack);
			return (NULL);
		}
		stack_add_back(new_stack, new_node);
		original_stack_top = original_stack_top->next;
	}
	return (new_stack);
}

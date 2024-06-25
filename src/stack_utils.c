/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:42:35 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/25 10:21:30 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Creates a stack and returns it */
t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	return (stack);
}

/* Initializes stack */
void	stack_init(t_stack *stack)
{
	stack->top = NULL;
}

/* Returns the size of the stack */
int	stack_size(t_stack *stack)
{
	t_node	*temp;
	int		size;

	temp = stack->top;
	size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

/* Returns true if stack is empty, false is not empty */
bool	is_stack_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (true);
	return (false);
}

/* adds a node to the back of a stack */
void	stack_add_back(t_stack *stack, t_node *new_node)
{
	t_node	*last_node;

	if (!stack || !new_node)
		return ;
	if (is_stack_empty(stack))
		stack->top = new_node;
	else
	{
		last_node = stack->top;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_cleanup.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:27:28 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/27 16:29:28 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error_exit(int exit_code)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(exit_code);
}

void	cleanup(t_stack *stack_a, t_stack *stack_b, int exit_code)
{
	free_stacks(&stack_a, &stack_b);
	if (exit_code == EXIT_FAILURE)
		display_error_exit(exit_code);
	else if (exit_code == EXIT_EMPTY_STRING)
		exit(exit_code);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	stack_free(stack_a);
	stack_free(stack_b);
}

void	stack_free(t_stack **stack)
{
	t_node	*temp;

	while ((*stack)->top)
	{
		temp = (*stack)->top;
		(*stack)->top = (*stack)->top->next;
		temp->num = 0;
		temp->index = 0;
		free(temp);
	}
	free(*stack);
	*stack = NULL;
}

void	free_2d(void ***thing)
{
	int		i;
	void	**arr;

	i = 0;
	if (*thing == NULL)
		return ;
	arr = *thing;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	*thing = NULL;
}

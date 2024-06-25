/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:27:23 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/27 16:47:13 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		parse_result;

	if (argc < 2)
		return (1);
	stack_a = create_stack();
	stack_b = create_stack();
	stack_init(stack_a);
	stack_init(stack_b);
	parse_result = parse_input(argc, argv, stack_a);
	if (parse_result == 0)
	{
		if (!is_stack_sorted(stack_a))
			sort(stack_a, stack_b);
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	else
		cleanup(stack_a, stack_b, parse_result);
}

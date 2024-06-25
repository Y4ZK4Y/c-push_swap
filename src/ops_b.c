/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_b.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/01 12:23:22 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/23 18:37:23 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sb(t_stack *b)
{
	stack_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	stack_push_to(&a, &b);
	ft_putstr_fd("pb\n", 1);
}

void	rb(t_stack *b)
{
	stack_rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack *b)
{
	stack_reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

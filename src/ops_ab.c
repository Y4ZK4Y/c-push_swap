/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_ab.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/01 12:25:36 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/23 18:37:18 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}

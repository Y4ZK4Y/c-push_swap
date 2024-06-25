/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_a.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/01 12:17:45 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/24 12:53:06 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sa(t_stack *a)
{
	stack_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	pa(t_stack *a, t_stack *b)
{
	stack_push_to(&b, &a);
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_stack *a)
{
	stack_rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_stack *a)
{
	stack_reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

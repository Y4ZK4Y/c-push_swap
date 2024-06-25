/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:27:14 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/25 10:27:37 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	check_empty_string(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '\0')
			return (EXIT_EMPTY_STRING);
	}
	return (0);
}

static int	validate_string(char **args, int j)
{
	int	k;

	k = 0;
	while (args[j][k] != '\0')
	{
		if (!ft_isdigit(args[j][k]) && !(k == 0 && (args[j][k] == '-' \
												|| args[j][k] == '+')))
		{
			free_2d((void ***)&args);
			return (1);
		}
		k++;
	}
	if (!ft_isdigit(*args[j]) && *args[j] != '-' && *args[j] != '+')
	{
		free_2d((void ***)&args);
		return (1);
	}
	return (0);
}

static int	convert_and_push(char **args, int j, t_stack *stack_a)
{
	int		value;
	t_node	*node;

	value = ft_atoi(args[j]);
	if (value >= INT_MAX || value <= INT_MIN)
	{
		free_2d((void ***)&args);
		return (1);
	}
	if (is_node_duplicate(stack_a->top, value))
	{
		free_2d((void ***)&args);
		return (1);
	}
	node = create_new_node(value);
	if (node == NULL)
	{
		free_2d((void ***)&args);
		return (1);
	}
	stack_push(stack_a, node);
	return (0);
}

int	parse_input(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	char	**args;
	int		j;

	if (check_empty_string(argc, argv) == EXIT_EMPTY_STRING)
		return (EXIT_EMPTY_STRING);
	i = argc;
	while (--i > 0)
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		while (args[j] != NULL)
			j++;
		j--;
		while (j >= 0)
		{
			if (validate_string(args, j) == 1)
				return (1);
			if (convert_and_push(args, j, stack_a) == 1)
				return (1);
			j--;
		}
		free_2d((void ***)&args);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indexer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:17:55 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/25 10:21:36 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_hash_table	*create_mapping_table(t_stack *sorted_stack)
{
	t_node			*current_node;
	int				index;
	t_hash_table	*mapping_table;

	if (!sorted_stack)
		return (NULL);
	mapping_table = table_create(stack_size(sorted_stack));
	current_node = sorted_stack->top;
	index = 0;
	while (current_node)
	{
		table_insert(mapping_table, current_node->num, index);
		current_node = current_node->next;
		index++;
	}
	return (mapping_table);
}

/* returns 1 for failure, 0 for success - creates a hash table 
and map the indices of the original stack to the sorted stack */
int	map_values_to_indices(t_stack *original_stack, t_hash_table *mapping_table)
{
	t_node		*current_node;
	int			mapped_index;

	if (!original_stack || !mapping_table)
		return (1);
	current_node = original_stack->top;
	while (current_node)
	{
		mapped_index = table_search(mapping_table, current_node->num);
		if (mapped_index == -1)
		{
			table_delete(mapping_table);
			return (1);
		}
		current_node->index = mapped_index ;
		current_node = current_node->next;
	}
	table_delete(mapping_table);
	return (0);
}

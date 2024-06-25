/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:26:38 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/21 17:21:35 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Creates a new node */
t_node	*create_new_node(int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->num = num;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

/* Checks for duplicate nodes */
bool	is_node_duplicate(t_node *head, int num)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp->num == num)
			return (true);
		temp = temp->next;
	}
	return (false);
}

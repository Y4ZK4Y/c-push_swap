/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indexer_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:18:41 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/23 18:04:38 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/* Creates and initializes the hash table */
t_hash_table	*table_create(int size)
{
	t_hash_table	*table;

	table = malloc(sizeof(t_hash_table));
	table->size = size;
	table->count = 0;
	table->items = ft_calloc((size_t)table->size, sizeof(t_hash_item *));
	return (table);
}

void	table_delete(t_hash_table	*table)
{
	t_hash_item	*item;
	int			i;

	i = 0;
	while (i < table->size)
	{
		item = table->items[i];
		if (item != NULL)
			free(item);
		i++;
	}
	free(table->items);
	free(table);
}

/* calculate a hash value for a given key to determine 
the slot in the hash table where the key should be stored .*/
unsigned int	hash_function(int key, const int a, const int m)
{
	long long	key_long;
	int			index;

	key_long = (long long) key;
	index = (int)((a * key_long) % m);
	if (index < 0)
		index += m;
	return (index);
}

void	table_insert(t_hash_table *table, int key, int value)
{
	t_hash_item	*item;
	int			index;

	item = malloc(sizeof(t_hash_item));
	item->key = key;
	item->value = value;
	index = hash_function(key, 151, table->size);
	while (table->items[index] != NULL)
	{
		if (table->items[index]->key == key)
		{
			free(table->items[index]);
			break ;
		}
		index = (index + 1) % table->size;
	}
	table->items[index] = item;
	table->count++;
}

/* search for a key in the hash table and returns its value 
returns -1 if key not found */
int	table_search(t_hash_table *table, int key)
{
	int	index;

	index = hash_function(key, 151, table->size);
	while (table->items[index] != NULL)
	{
		if (table->items[index]->key == key)
			return (table->items[index]->value);
		index = (index + 1) % table->size;
	}
	return (-1);
}

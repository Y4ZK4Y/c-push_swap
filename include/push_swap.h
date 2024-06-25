/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:27:36 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/25 10:23:28 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

#define EXIT_EMPTY_STRING 2

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
}				t_stack;

typedef struct s_hash_item
{
	int	key;
	int	value;
}		t_hash_item;

typedef struct s_hash_table
{
	int			size;
	int			count;
	t_hash_item	**items;
}				t_hash_table;

/* Parsing */
int				parse_input(int argc, char **argv, t_stack *stack_a);

/* Node utils */
t_node			*create_new_node(int num);
bool			is_node_duplicate(t_node *head, int num);

/* Error and Cleanup */
void			display_error_exit(int exit_code);
void			ft_putstr_fd(char *s, int fd);
void			cleanup(t_stack *stack_a, t_stack *stack_b, int exit_code);
void			free_stacks(t_stack **stack_a, t_stack **stack_b);
void			stack_free(t_stack **stack);
void			free_2d(void ***thing);

/* Stack utils */
t_stack			*create_stack(void);
void			stack_init(t_stack *stack);
int				stack_size(t_stack *stack);
bool			is_stack_empty(t_stack *stack);
t_stack			*stack_copy(const t_stack *original_stack);
void			stack_add_back(t_stack *stack, t_node *new_node);

/* Stack Ops */
void			stack_push(t_stack *stack, t_node *node);
int				stack_pop(t_stack *stack);
int				stack_peek(t_stack *stack);
bool			is_stack_sorted(t_stack *stack);
void			stack_swap(t_stack *stack);
void			stack_push_to(t_stack **from, t_stack **to);
void			stack_rotate(t_stack *stack);
void			stack_reverse_rotate(t_stack *stack);

/* Push_swap Operations on stack a */
void			sa(t_stack *a);
void			pa(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rra(t_stack *a);

/* Push_swap Operations on stack b */
void			sb(t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			rb(t_stack *b);
void			rrb(t_stack *b);

/* Push_swap Operations on stacks a and b */
void			ss(t_stack *a, t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rrr(t_stack *a, t_stack *b);

/* Sort */
int				sort(t_stack *a, t_stack *b);
void			small_sort(t_stack *stack);
void			sort_4(t_stack *stack_a, t_stack *stack_b);
void			sort_5(t_stack *stack_a, t_stack *stack_b);
int				big_sort(t_stack **stack_a, t_stack **stack_b);

/* Big sort */
int				bubblesort(t_stack *stack);
void			radix_sort(t_stack **stack_a, t_stack **stack_b);

/* Indexer */
t_hash_table	*create_mapping_table(t_stack *sorted_stack);
int				map_values_to_indices(t_stack *original_stack, \
									t_hash_table *mapped_table);

/* Indexer Utils */
int				table_search(t_hash_table *table, int key);
void			table_insert(t_hash_table *table, int key, int value);
unsigned int	hash_function(int key, const int a, const int m);
void			table_delete(t_hash_table	*table);
t_hash_table	*table_create(int size);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:57:10 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/12 15:51:42 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sorted(t_node *stack)
{
	t_node	*current_node;

	if (!stack)
		return (1);
	current_node = stack;
	while (current_node->next != NULL)
	{
		if (current_node->num > current_node->next->num)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

static void	sort_three(t_node **stack)
{
	t_node	*highest;

	highest = find_max(*stack);
	if (highest == *stack)
		ra(stack);
	else if ((*stack)->next == highest)
		rra(stack);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

static void	sort_four_five(t_node **a, t_node **b)
{
	t_node	*min_node;

	while (count_nodes(*a) > 3)
	{
		min_node = find_min(*a);
		current_index(*a);
		move_to_top(a, min_node, 'a');
		pb(b, a);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

static void	sort_more(t_node **a, t_node **b)
{
	int	len_a;

	len_a = count_nodes(*a);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !check_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	put_min_ontop(a);
}

void	sort_stack(t_node **a, t_node **b)
{
	if (count_nodes(*a) == 0)
	{
		free_stack(a);
		error_n_exit(NULL, 0);
	}
	if (check_sorted(*a) == 1)
	{
		free_stack(a);
		exit(0);
	}
	if (count_nodes(*a) == 2)
		sa(a);
	else if (count_nodes(*a) == 3)
		sort_three(a);
	else if (count_nodes(*a) == 4 || count_nodes(*a) == 5)
		sort_four_five(a, b);
	else
		sort_more(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:57:10 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 13:50:27 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sorted(t_node *stack)
{
	t_node	*current_node;

	if (!stack)
		return (1);//is this right?
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
	if (highest == *stack)//if highest at top, rotate to bottom.
		ra(stack);
	else if ((*stack)->next == highest)//if highest at 2nd position, rev rotate to bring last (3rd) to top, thus moving 2nd to bottom.
		rra(stack);
	if ((*stack)->num > (*stack)->next->num)//if 1st is greater than 2nd, swap. the highest is already at bottom following previous if/else.
		sa(stack);
}

static void	sort_five(t_node **a, t_node **b)
{
	t_node	*min_node;

	while (count_nodes(*a) > 3)//until reaches 3 nodes in stack A, brings min value to top of A and pushes to B. B will be in descending order.
	{
		min_node = find_min(*a);
		current_index(*a);//sets index and median for next operation.
		move_to_top(a, min_node, 'a');//move min node to top
		pb(b, a);//push to B
	}
	sort_three(a);//sorts 3 nodes left in stack A. B is sorted with next highest on top, ready to push to A.
	pa(a, b);
	pa(a, b);
}

static void	sort_more(t_node **a, t_node **b)
{
	int	len_a;

	len_a = count_nodes(*a);//sets length for iteration down to 3.
	if (len_a-- > 3 && !check_sorted(*a))//if more than 3 nodes that arent sorted, push top two nodes to B as reference nodes.
		pb(b, a);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !check_sorted(*a))//until only 3 nodes, initiate and push to B.
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
	put_min_ontop(a);//once nodes in A are sorted, rotates/rev_rotates to bring min. value to top.
}

void	sort_stack(t_node **a, t_node **b)
{
	if (count_nodes(*a) == 0)//if no nodes to sort, frees stack, prints error, and exits.
	{
		free_stack(a);
		error_n_exit(NULL, 0);
	}
	if (check_sorted(*a) == 1)//if already sorted, free stack and exit.
	{
		free_stack(a);
		exit(1);
	}
	if (count_nodes(*a) == 2)//for 2 unsorted nodes, swap.
		sa(a);
	else if (count_nodes(*a) == 3)
		sort_three(a);
	else if (count_nodes(*a) == 5)
		sort_five(a, b);
	else
		sort_more(a, b);
}

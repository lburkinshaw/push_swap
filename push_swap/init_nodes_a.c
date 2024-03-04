/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:16:49 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 13:49:54 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_node *stack)
{
	int		median;
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack;
	median = count_nodes(temp) / 2;
	if (!temp)
		return ;
	while (temp)
	{
		temp->index = i;
		if (temp->index < median)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		i++;
		if (!temp->next)
			return ;
		temp = temp->next;
	}
}

static void	set_target_a(t_node *a, t_node *b)//sets target in B for each A node: closest lower value.
{
	t_node	*curr_a;
	t_node	*curr_b;
	t_node	*target_node;
	long	best_match;

	curr_a = a;
	while (curr_a)
	{
		best_match = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if ((curr_b->num < curr_a->num) && curr_b->num > best_match)//if num in B is less than A and greater than best match (thus closer to A)
			{
				best_match = curr_b->num;//save num as best match (long)
				target_node = curr_b;//set node temporarily as target
			}
			curr_b = curr_b->next;//iterate through all nodes in B
		}
		if (best_match == LONG_MIN)//therefore no smaller number found in B and A will be min value.
			curr_a->target_node = find_max(b);//set temp target as highest num in B, completing 'circle'.
		else
			curr_a->target_node = target_node;//if best match found (and saved as target), set A's target node as temporary target
		curr_a = curr_a->next;//iterate through all nodes in A
	}
}

static void	cost_analysis_a(t_node *a, t_node *b)//sets push_cost for each node in A.
{
	int		len_a;
	int		len_b;
	t_node	*curr_a;

	len_a = count_nodes(a);
	len_b = count_nodes(b);
	curr_a = a;
	while (curr_a)
	{
		curr_a->push_cost = curr_a->index;
		if (curr_a->above_median == 0)//if A node is below median, subtract index from length (otherwise push_cost remains its index)
			curr_a->push_cost = len_a - curr_a->index;
		if (curr_a->target_node->above_median == 1)//if target in B is above median, add its index to push_cost
			(curr_a->push_cost = curr_a->push_cost + curr_a->target_node->index);
		else// if B target is below median, add B length - node index to push_cost.
			(curr_a->push_cost = curr_a->push_cost + (len_b - curr_a->target_node->index));
		curr_a = curr_a->next;
	}
}

static void	set_cheapest(t_node *stack)//compares push_cost of nodes and sets 1 as cheapest.
{
	long	cheapest_num;
	t_node	*cheapest_node;//ptr to point to cheapest node so far as iterating through. when complete sets its "cheapest" value to 1.
	t_node	*current;

	if (!stack)
		error_n_exit(NULL, 0);
	current = stack;
	cheapest_num = LONG_MAX;
	while (current)
	{
		if (current->push_cost < cheapest_num)
		{
			cheapest_num = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_nodes_a(t_node *a, t_node *b)
{
	current_index(a);//adds index to A nodes and position above/below median. 
	current_index(b);//as  above for B.
	set_target_a(a, b);//sets target in B for each A node: closest lower value.
	cost_analysis_a(a, b);//stores push_cost for each node in A.
	set_cheapest(a);//compares push_costs and sets "cheapest" value as 1 for chepaest node.
}

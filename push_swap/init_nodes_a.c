/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:16:49 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/28 11:08:28 by lburkins         ###   ########.fr       */
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
	/*if (median == 0)
	{
		temp->index = 0;
		temp
	}*/
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

void	set_target_a(t_node **a, t_node **b)
{
	t_node	*curr_a;
	t_node	*curr_b;
	t_node	*target_node;
	long	best_match;

	curr_a = *a;
	while (curr_a)
	{
		best_match = LONG_MIN;
		curr_b = *b;
		while (curr_b)
		{
			if ((curr_b->num < curr_a->num) && curr_b->num > best_match)//if num in b is less than a and greater than best match (thus closer to a)
			{
				best_match = curr_b->num;//save num as best match (long)
				target_node = curr_b;//set node as temp target
			}
			curr_b = curr_b->next;//iterate through all nodes in b
		}
		if (best_match == LONG_MIN)//therefore no smaller number found in b
			curr_a->target_node = find_max(*b);//set temp target as highest num in b, completing 'circle'.
		else
			curr_a->target_node = target_node;//if best match found (and saved as target), set a's target node as tempp target
		curr_a = curr_a->next;//iterate through all nodes in a
	}
}

void	cost_analysis_a(t_node **a, t_node **b)
{
	int	len_a;
	int	len_b;
	t_node	*curr_a;//by adding this i seem to have pushed back the segfault to after pushing all nodes to B!

	len_a = count_nodes(*a);
	len_b = count_nodes(*b);
	curr_a = *a;
	while (curr_a)
	{
		curr_a->push_cost = curr_a->index;
		if (curr_a->above_median == 0)//if a node is below median, subtract index from length (otherwise push_cost remains its index)
			curr_a->push_cost = len_a - curr_a->index;
		if (curr_a->target_node->above_median == 1)//if target in b is above median, add its index to push_cost
			(curr_a->push_cost = curr_a->push_cost + curr_a->target_node->index);
		else// if b target is below median
			(curr_a->push_cost = curr_a->push_cost + (len_b - curr_a->target_node->index));
		curr_a = curr_a->next;
	}
}
void	set_cheapest(t_node **stack)
{
	long	cheapest_num;
	t_node	*cheapest_node;
	t_node	*current;

	if (!stack)
		error_n_exit(NULL, 0);
	current = *stack;
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

void	init_nodes_a(t_node **a, t_node **b)
{
	current_index(*a);
	current_index(*b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:16:49 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/05 13:45:34 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_node *stack)
{
	int		median;
	int		i;
	t_node	*curr;

	i = 0;
	curr = stack;
	median = count_nodes(curr) / 2;
	if (!curr)
		return ;
	while (curr)
	{
		curr->index = i;
		if (curr->index <= median)
			curr->above_median = 1;
		else
			curr->above_median = 0;
		i++;
		if (!curr->next)
			return ;
		curr = curr->next;
	}
}

static void	set_target_a(t_node *a, t_node *b)
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
			if ((curr_b->num < curr_a->num) && curr_b->num > best_match)
			{
				best_match = curr_b->num;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match == LONG_MIN)
			curr_a->target_node = find_max(b);
		else
			curr_a->target_node = target_node;
		curr_a = curr_a->next;
	}
}

static void	cost_analysis(t_node *a, t_node *b)
{
	int		len_a;
	int		len_b;
	int		diff;
	t_node	*curr_a;

	len_a = count_nodes(a);
	len_b = count_nodes(b);
	diff = 0;
	curr_a = a;
	while (curr_a)
	{
		if (curr_a->above_median)
			curr_a->push_cost = curr_a->index;
		if (curr_a->above_median == 0)
			curr_a->push_cost = len_a - curr_a->index;
		if (curr_a->target_node->above_median)
			(curr_a->push_cost += curr_a->target_node->index);
		else
		{
			diff = len_b - curr_a->target_node->index;
			curr_a->push_cost += diff;
		}
		curr_a = curr_a->next;
	}
}

static void	set_cheapest(t_node *stack)
{
	long	cheapest_num;
	t_node	*cheapest_node;
	t_node	*current;

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
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}

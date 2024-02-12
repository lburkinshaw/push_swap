/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:53:03 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/12 16:15:43 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(t_node *stack)
{
	t_node	*max_node;
	t_node	*current_node;
	t_node	*next_node;
	int		max;

	if (!stack)
		return (NULL);
	current_node = stack;
	next_node = stack->next;
	max = INT_MIN;
	while (next_node)
	{
		if (current_node->num > next_node->num && current_node->num > max)
			max_node = current_node;
		else
		{
			if (current_node->num > max)
				max_node = next_node;
		}	
		max = max_node->num;
		current_node = current_node->next;
		next_node = next_node->next;
	}
	ft_printf("max value is: %d\n", max_node->num);
	return (max_node);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min_node;
	t_node	*current_node;
	t_node	*next_node;
	int		min;

	if (!stack)
		return (NULL);
	current_node = stack;
	next_node = stack->next;
	min = INT_MAX;

	while (next_node)
	{
		if (current_node->num < next_node->num && current_node->num < min) // should it be "<= min" to allow for int min?
			min_node = current_node;
		else
		{	
			if (current_node->num < min)
				min_node = next_node;
		}
		min = min_node->num;
		current_node = current_node->next;
		next_node = next_node->next;
	}
	ft_printf("min value is: %d\n", min_node->num);
	return (min_node);
}

//find_max
//find_min

//Move here:
	//--find_last 
	//--check sorted
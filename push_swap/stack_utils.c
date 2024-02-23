/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:41:28 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/23 14:38:28 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_node(t_node *lst)
{
	t_node	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

int	count_nodes(t_node *lst)
{
	int		count;
	t_node	*ptr;

	if (!lst)
		return (0);
	count = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	/*printf("No. of nodes: %d\n", count);
	printf("list start\n");
	retrieve_stack(lst);
	printf("list end\n");*/ //COUNT FUNCTION SEEMS TO WORK CORRECTLY.
	return (count);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max_node;
	t_node	*current_node;
	int		max;

	if (!stack)
		return (NULL);
	current_node = stack;
	max = INT_MIN;
	while (current_node)
	{
		if (current_node->num > max)
		{
			max = current_node->num;
			max_node = current_node;
		}
		current_node = current_node->next;
	}
	return (max_node);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min_node;
	t_node	*current_node;
	int		min;

	if (!stack)
		return (NULL);
	current_node = stack;
	min = INT_MAX;

	while (current_node)
	{
		if (current_node->num < min)
		{
			min = current_node->num;
			min_node = current_node;
		}
		current_node = current_node->next;
	}
	ft_printf("min value is: %d\n", min_node->num);
	return (min_node);
}

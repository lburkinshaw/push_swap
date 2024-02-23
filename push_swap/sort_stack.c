/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:57:10 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/23 15:03:48 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_node *stack)
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

void	sort_three(t_node **stack)
{
	t_node	*highest;

	highest = find_max(*stack);
	if (highest == *stack)
		ra(stack, 0);//not sure about 0/1 value here for print. why is it necessary? found on thuggonaut.
	else if ((*stack)->next == highest)
		rra(stack, 0);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack, 0);
}

void	sort_more(t_node **a, t_node **b)
{
	int	len_a;

	len_a = count_nodes(*a);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a, 0);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a, 0);
	while (len_a > 3)
	{
		init_nodes_a(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	printf("stack A:\n");
	retrieve_stack(*a);//remove
	printf("stack B:\n");//remove
	retrieve_stack(*b);//remove
	printf("number of nodes in B: %d\n", count_nodes(*b));//remove
	while (*b)
	{
		init_nodes_b(a, b);
		printf("B num: %d\n", (*b)->num);
		//printf("B target: %d\n", (*b)->target_node->num); // doesnt seem to have assigned target
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
		error_n_exit(NULL, 0);//do i need to print error?
	}
	if (check_sorted(*a) == 1)
		exit(1);
	if (count_nodes(*a) == 2)
		sa(a, 0);
	if (count_nodes(*a) == 3)
		sort_three(a);
	else
		//radix_sort(a, b);
		sort_more(a, b);
}

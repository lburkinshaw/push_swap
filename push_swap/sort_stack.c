/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:57:10 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/29 12:07:01 by lburkins         ###   ########.fr       */
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
	//printf("stack A len: %d\n", len_a);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a, 0);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a, 0);
	while (len_a-- > 3 && !check_sorted(*a))
	{
		init_nodes_a(a, b);
		move_a_to_b(a, b);
	}
	/*while (len_a-- > 3  && !check_sorted(*a))//the above segfaults when more than 5 values (i.e. when enters while loop). This way nums are sorted but may be less efficient than if i correct above code..
		pb(b, a, 0);*/
	sort_three(a);
	//printf("stack A:\n");
	//retrieve_stack(*a);//remove
	//printf("stack B:\n");//remove
	//retrieve_stack(*b);//remove
	while (*b)
	{
		init_nodes_b(a, b);
		move_b_to_a(a, b);
	}
	//printf("stack A b4 min on top:\n");//remove
	//retrieve_stack(*a);//remove
	current_index(*a);
	put_min_ontop(a);
}

void	handle_five(t_node **a, t_node **b)
{
	t_node	*min_node;

	while (count_nodes(*a) > 3)
	{
		min_node = find_min(*a);
		//ft_printf("%d\n", min_node->num);
		current_index(*a);
		move_to_top(a, min_node, 'a');
		pb(b, a, 0);//problem seems to be here, looping on one
		//retrieve_stack(*b);
	}
	sort_three(a);
	pa(a, b, 0);
	pa(a, b, 0);
	/*while (*b)
	{
		init_nodes_b(a, b);
		move_b_to_a(a, b);
	}
	put_min_ontop(a);*/
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
	if (count_nodes(*a) == 5)
		handle_five(a, b);
	else
		//radix_sort(a, b);
		sort_more(a, b);
}

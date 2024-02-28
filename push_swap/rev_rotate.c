/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:11:22 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/26 15:08:25 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **stack)
{
	/*t_node	*last_node;
	t_node	*new_bottom;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	new_bottom = last_node->prev;
	new_bottom->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	if (last_node->next != NULL)
		last_node->next->prev = NULL;*/
	t_node	*last_node; //To store the pointer to the last node

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last_node->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last_node->prev = NULL; //Detach itself from the node before it
	*stack = last_node;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last_node->next->prev = last_node; //Update the current last node of the stack
}

void	rra(t_node **a, int print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, int print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rrr(a, b, 0);
	current_index(*a);//refresh indexes after operation.
	current_index(*b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:57:10 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/16 15:03:43 by lburkins         ###   ########.fr       */
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
		{
			ft_printf("not sorted\n");
			return (0);
		}
		current_node = current_node->next;
	}
	ft_printf("sorted\n");
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

/*void	sort_more(t_node **a, t_node **b)
{

}*/

void	sort_stack(t_node **a, t_node **b)
{
	(void)b;
	if (count_nodes(*a) == 0)
		exit(1);//print error?
	if (check_sorted(*a) == 1)
		exit(1);
	if (count_nodes(*a) == 2)
		sa(a, 0);
	if (count_nodes(*a) == 3)
		sort_three(a);
	/*else
		sort_more(a, b);*/
}

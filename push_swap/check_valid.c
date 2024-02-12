/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:06:25 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/12 13:56:25 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_repeat_stack(t_node *stack)
{
	t_node	*current_ptr;
	t_node	*nxt_ptr;

	if (stack == NULL)
		return (1);
	current_ptr = stack;
	nxt_ptr = current_ptr->next;
	while (current_ptr->next != NULL/* && nxt_ptr != NULL*/)
	{
		while (current_ptr->num != nxt_ptr->num && nxt_ptr->next != NULL)
			nxt_ptr = nxt_ptr->next;
		if (current_ptr->num == nxt_ptr->num)
			return (1);
		current_ptr = current_ptr->next;
	}
	return (0);
}

int	check_digit(char *nums)
{
	int	i;

	i = 0;
	if (nums[0] == '-' || nums[0] == '+')
		i++;
	while (nums[i])
	{
		if (nums[i] < 48 || nums[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	check_valid(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		j = 0;
		if (check_digit(nums[i]))
			return (1);
		j = ft_strlen(nums[i]);
		if (j > 11)
			return (1);
		if (ft_atol(nums[i]) < -2147483648 || ft_atol(nums[i]) > 2147483647)//do i need to free something?
			return (1);
		i++;
	}
	return (0);
}

/*Need to create/split into:
-->
--> a check digit function that also handles the cases of '+' and '-', 
and gives error when '++' or '--' and also if '+6 6'
--> function to check for overflow.
--> function to check for repeat numbers after atol??*/
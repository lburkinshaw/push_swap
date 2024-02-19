/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:30:58 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/16 15:06:15 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(t_node *stack)
{
	t_node	*current_ptr;
	t_node	*nxt_ptr;

	if (stack == NULL)
		return (1);
	current_ptr = stack;
	nxt_ptr = current_ptr->next;
	while (current_ptr->next)
	{
		while (nxt_ptr && current_ptr->num != nxt_ptr->num)//need to check for next_ptr before trying to access
			nxt_ptr = nxt_ptr->next;
		if (nxt_ptr && current_ptr->num == nxt_ptr->num)//need to check for next_ptr before trying to access
			return (1);
		current_ptr = current_ptr->next;
		if (current_ptr)
			nxt_ptr = current_ptr->next;
	}
	return (0);
}

int	check_digit(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] < 48 || arg[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	check_valid(char **args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (args[i])
	{
		if (check_digit(args[i]))
			return (1);
		len = ft_strlen(args[i]);
		if (len > 11)
			return (1);
		if (ft_atol(args[i]) < INT_MIN || ft_atol(args[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

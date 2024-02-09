/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:27:17 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/09 15:36:40 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_n_exit(void)
{
	ft_printf("error\n");
	exit (1);
}

void	free_split(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);//is this correct &/or necessary??
}

void	free_stack(t_node **stack, int error)
{
	t_node	*current;
	t_node	*previous;

	if (!stack)
		return ;
	current = *stack;
	previous = *stack;
	while (current->next)
	{
		current = current->next;
		free(previous);
		previous = current;
	}
	*stack = NULL;
	if (error)
		error_n_exit();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:19:14 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/19 11:34:25 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_num(int nb, t_node **stack)
{
	t_node	*new_node;
	t_node	*last_node;
	//error check for if !stack ???
	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(stack, 0);//should i print error message?
		exit(1);
	}
	new_node->next = NULL;
	new_node->num = nb;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	add_to_stack(char **arguments, t_node **stack)
{
	int	i;
	int	nb;

	i = 0;
	while (arguments[i])
	{
		nb = ft_atoi(arguments[i]);
		append_num(nb, stack);
		i++;
	}
}

void	initiate_a(int ac, char *av[], t_node **stack)
{
	char	**arguments;
	int		free_flag;
	int		i;

	arguments = NULL;
	free_flag = 0;
	i = 0;
	if (ac == 2)
	{
		arguments = ft_split(av[1], ' ');
		if (!arguments)
			exit(1);//check
		free_flag = 1;
	}
	else
		arguments = av + 1;
	if (av[1] == NULL)
		exit(1);//check - just exit because only one argument
	if (check_valid(arguments) == 1)
		error_n_exit();
	add_to_stack(arguments, stack);
	if (check_dups(*stack) == 1)
		free_stack(stack, 1);
	if (free_flag)
		free_split(arguments);
}


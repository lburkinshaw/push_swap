/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_n_retrieve_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:17:53 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/12 13:59:40 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_nb(long int nb, t_node **stack)
{
	t_node	*new_node;
	t_node	*last_ptr;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->num = nb;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_ptr = find_last_node(*stack);
	last_ptr->next = new_node;
}

void	retrieve_stack(t_node *stack)
{
	t_node	*ptr;

	if (stack == NULL)
		return ;
	ptr = stack;
	while (ptr)
	{
		ft_printf("%d\n", ptr->num);
		ptr = ptr->next;
	}
}

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

void	add_args_to_stack(char **arguments, t_node **stack)
{
	int	i;
	int	nb;

	i = 0;
	while (arguments[i]) //add to stack
	{
		nb = ft_atoi(arguments[i]); //convert str to long int -- need to create own function.
		add_nb(nb, stack);//return number of items in stack?? to use for stack b and sorti ng algorithm choice?
		i++;
	}
}

int initiate_stack_a(int ac, char *av[], t_node **stack)
{
	char		**arguments;
	int			free_flag;

	arguments = NULL;
	free_flag = 0;
	if (ac == 2) //Check if the argument count is 2 and the 2nd is not empty, this implies a string
	{
		arguments = ft_split(av[1], ' ');
		free_flag = 1;
	}
	else
		arguments = av + 1;
	if (!arguments[1])
		return (1);
	if (check_valid(arguments) == 1)
		error_n_exit(); //ft_putendl_fd("error", 2);
	add_args_to_stack(arguments, stack);
	if (check_repeat_stack(*stack) == 1)//this can go in main to save lines if necessary
		free_stack(stack, 1);
	if (free_flag) //check this is right.
		free_split(arguments);
	return (0);
}
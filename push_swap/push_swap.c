/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:18:31 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/09 13:39:14 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Make work for 3 numbers:
./push_swap 2 5 1
./push_swap "2 5 1"

Steps:
- Create stack, -ok
- Add each no. to stack -ok
- Retrieve stack -ok

ERROR CHECKS:
- If repeat, don't put on list (print error or just omit??)
- If more than 11 characters
- check if outside max/min int
--> print error message or initiate stackk


-- rotate stack a
-- swap stack a
*/

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
	if (stack == NULL)
		return ;
	t_node *ptr = stack;
	while (ptr)
	{
		ft_printf("%d\n", ptr->num);
		//ft_putnbr_fd(stack->num, 1);//change to ft_printf?
		//ft_putchar_fd('\n', 1);
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
	int i;
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
		return (write(2, "error\n", 6)); //ft_putendl_fd("error", 2);
	
	add_args_to_stack(arguments, stack);
	if (check_repeat_stack(*stack) == 1)//this can go in main to save lines if necessary
	{
		write(2, "error\n", 6);
		free(*stack);
		return (1);
	}
	if (free_flag)//check this is right.
		free(arguments);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_node		*stack;

	stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //Check for incorrect argument counts or if the 2nd argument is `0`
		return (1);
	if (initiate_stack_a(argc, argv, &stack) == 1) //Checks that more than one number
		return (1);
	//initiate stack b
	//sort 3
	retrieve_stack(stack);
	free(stack);
	return (0);
}
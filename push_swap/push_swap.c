/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:18:31 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/01 16:09:16 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Make work for 3 numbers:
./push_swap 2 5 1
./push_swap "2 5 1"

Steps:
- Create stack, 
- Add each no. to stack
- Retrieve stack
*/

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>


void	add_to_stack(long int nb, t_Node **stack)
{
	t_Node	*new_node;
	t_Node	*last_ptr;

	new_node = malloc(sizeof(t_Node));
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

void	retrieve_stack(t_Node *stack)
{
	if (stack == NULL)
		return ;
	while (stack)
	{
		ft_putnbr_fd(stack->num, 1);
		stack = stack->next;
		ft_putchar_fd('\n', 1);
	}
}


t_Node    *find_last_node(t_Node *lst)
{
    t_Node    *ptr;

    if (lst == NULL)
        return (NULL);
    
    ptr = lst;
    while (ptr->next != NULL)
         ptr = ptr->next;
    return (ptr);
}
int	main(int argc, char *argv[])
{
	int			i;
	long int	nb;
	t_Node		*stack = NULL;
	int			argc_flag;

	argc_flag = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //Check for incorrect argument counts or if the 2nd argument is `0`
		return (1);
	else if (argc == 2) //Check if the argument count is 2 and the 2nd is not empty, this implies a string
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		while (argv[i]) //add to stack
		{
			nb = ft_atol(argv[i]); //convert str to long int -- need to create own function.
			add_to_stack(nb, &stack);
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < argc) //add to stack
		{
			nb = ft_atol(argv[i]); //convert str to long int -- need to create own function.
			add_to_stack(nb, &stack);
			i++;
		}
	}
	retrieve_stack(stack);
	free(stack);
	return(0);
}
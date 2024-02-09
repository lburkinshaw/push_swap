/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:18:31 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/08 17:01:49 by lburkins         ###   ########.fr       */
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

int count_strings(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (!i || s[i - 1] == c))
			j++;
		i++;
	}
	return (j);
}
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
		ft_printf("%d\n", stack->num);
		//ft_putnbr_fd(stack->num, 1);//change to ft_printf?
		//ft_putchar_fd('\n', 1);
		stack = stack->next;
		
	}
}

t_Node	*find_last_node(t_Node *lst)
{
	t_Node	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

int initiate_stack_a(int ac, char *av[], t_Node **stack)
{
	long int	nb;
	int			i;
	char		**arguments;
	
	arguments = NULL;
	if (ac == 2) //Check if the argument count is 2 and the 2nd is not empty, this implies a string
	{
		arguments = ft_split(av[1], ' ');
		/*while (av[i])
		{
			printf("%s\n", av[i]);
			i++;
		}	*/
	}
	else
		arguments = av + 1;
	if (!arguments[1])
			return (1);
	i = 0;
	if (check_valid(&arguments[i]) == 1)
	{
		ft_putendl_fd("error", 2);
		return(0);
	}
	while (arguments[i]) //add to stack
	{
		nb = ft_atol(arguments[i]); //convert str to long int -- need to create own function.
		add_to_stack(nb, stack);//return number of items in stack?? to use for stack b and sorti ng algorithm choice?
		i++;
	}
	return(0);
}

int	main(int argc, char *argv[])
{
	t_Node		*stack;

	stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //Check for incorrect argument counts or if the 2nd argument is `0`
		return (1);
	if (initiate_stack_a(argc, argv, &stack) == 1) //checks that more than one number
		return (1);
	//initiate stack b
	//sort 3
		retrieve_stack(stack);
	free(stack);
	return (0);
}
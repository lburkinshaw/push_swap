/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:40 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/09 10:08:25 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>

typedef struct Node
{
	int			num;
	struct Node	*next;
}	t_Node;

int		main(int argc, char	*argv[]);
void	add_to_stack(long int nb, t_Node **stack);
void	retrieve_stack(t_Node *stack);
t_Node	*find_last_node(t_Node *lst);
int		initiate_stack_a(int ac, char *av[], t_Node **stack);
int		check_valid(char *nums[]);
int 	check_repeat(char *current, char *next[], int i);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operators.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 14:10:56 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/26 13:19:37 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include <stdio.h>

void	swap_elems(int *old_top, int *new_top)
{
	int	temp;

	temp = *old_top;
	*old_top = *new_top;
	*new_top = temp;
}

void	swap_operator(t_stack *stack)
{
	if (stack->current_size <= 1)
		return ;
	else
		swap_elems(&(stack->stack[stack->current_size - 1]),
			&(stack->stack[stack->current_size - 2]));
}

void	push_operator(t_stack *giver, t_stack *receiver)
{
	if (giver->current_size == 0)
		return ;
	else
	{
		receiver->stack[receiver->current_size] = giver->stack
		[giver->current_size - 1];
		receiver->current_size++;
		giver->current_size--;
	}
}

void	reverse_rotate_operator(t_stack *a)
{
	size_t	i;
	int		first;

	i = 0;
	first = a->stack[0];
	while (i < a->current_size - 1)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = first;
}

void	rotate_operator(t_stack *a)
{
	int	i;
	int	last;

	last = a->stack[a->current_size - 1];
	i = a->current_size - 1;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[i] = last;
}

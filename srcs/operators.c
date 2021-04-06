/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operators.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 14:10:56 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/06 15:52:01 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/thimovandermeer/Desktop/Codam projecten/push_swap/includes/push_swap.h"
#include <stdio.h>
void	swap_elems(int *old_top, int *new_top)
{
	int temp;
	temp = *old_top;
	*old_top = *new_top;
	*new_top = temp;
}

void	swap_operator(t_stack *stack)
{
	if(stack->current_size <= 1)
		return ;
	else
		swap_elems(&(stack->stack[stack->current_size]), &(stack->stack[stack->current_size - 1]));
}

void	push_operator(t_stack *giver, t_stack *receiver)
{
	if (receiver->current_size == 0)
		return ;
	else
	{
		receiver->stack[receiver->current_size] = giver->stack[giver->current_size];
		receiver->current_size++;
		giver->current_size--;
	}
}

void	rotate_operator()
{

}

void	reverse_rotate_operator()
{
	
}


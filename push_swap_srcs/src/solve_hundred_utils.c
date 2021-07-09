/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:52:06 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/07/09 14:25:26 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# define SMALLEST_NUM 10000000

/*
*	This function returns the smallest number in the stack.
*	I have hardcoded the starting number which is dangerous.
*	For our use case however this limit is acceptable
*/


int	smallest_num(int *array, int len)
{
	int	i;
	int	smallest_num;

	smallest_num = SMALLEST_NUM;
	i = 0;
	while (i < len)
	{
		if (array[i] < smallest_num)
			smallest_num = array[i];
		i++;
	}
	return (smallest_num);
}

/*
* 	This function moves the number all the way down in the stack. At the end it pushes the number to the other stack
*/


void	move_down(int steps, t_stack *b, t_stack *a, int flag)
{
	int	i;

	i = 0;
	steps++;
	while (i < steps)
	{
		if (flag == 2)
			ft_putstr_fd("rrb\n", 1);
		else
			ft_putstr_fd("rra\n", 1);
		reverse_rotate_operator(b);
		i++;
	}
	if (flag == 2)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
	push_operator(b, a);
}

/*
* 	This function moves the number all the way up in the stack. At the end it pushes the number to the other stack
*/


void	move_up(int steps, t_stack *b, t_stack *a, int flag)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		rotate_operator(b);
		if (flag == 2)
			ft_putstr_fd("rb\n", 1);
		else
			ft_putstr_fd("ra\n", 1);
		i++;
	}
	push_operator(b, a);
	if (flag == 2)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

/*
*	This function calculate the steps it needs to take to move the number all the way down the stack
*/


int	steps_down(t_stack *a, int current_quarter, int *quarters)
{
	int	i;
	int	lowerbound;
	int	upperbound;

	i = 0;
	if (current_quarter == 0)
		lowerbound = 0;
	else
		lowerbound = quarters[current_quarter - 1] - 1;
	upperbound = quarters[current_quarter];
	while (i < a->current_size)
	{
		if (a->stack[i] >= lowerbound && a->stack[i] <= upperbound)
			return (i);
		i++;
	}
	return (-1);
}

/*
*	This function calculate the steps it needs to take to move the number all the way up the stack
*/


int	steps_up(t_stack *a, int current_quarter, int *quarters)
{
	int	i;
	int	lowerbound;
	int	upperbound;

	i = a->current_size;
	if (current_quarter == 0)
		lowerbound = 0;
	else
		lowerbound = quarters[current_quarter - 1];
	upperbound = quarters[current_quarter];
	while (i)
	{	
		if (a->stack[i] >= lowerbound && a->stack[i] <= upperbound)
			return (i);
		i--;
	}
	return (-1);
}

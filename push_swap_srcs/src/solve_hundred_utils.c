/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:52:06 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/29 14:39:41 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_num(int *array, int len)
{
	int	i;
	int	smallest_num;

	smallest_num = 100000;
	i = 0;
	while (i < len)
	{
		if (array[i] < smallest_num)
			smallest_num = array[i];
		i++;
	}
	return (smallest_num);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:52:06 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/22 13:14:16 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *array, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = 0;
	while (i < len - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

int	smallest_num(int *array, int len)
{
	int	i;
	int	smallest_number;

	i = len - 1;
	smallest_number = i;
	while (i)
	{
		if (array[i] <= smallest_number)
			smallest_number = array[i];
		i--;
	}
	return (smallest_number);
}

void 	fill_steps(t_steps *steps, t_stack *b)
{
	steps->big_up = 0;
	steps->small_up = 0;
	steps->big_down = 0;
	steps->small_down = 0;
	steps->big_up = b->current_size - pos_biggest_number(b->stack,
		b->current_size);
	steps->small_up = b->current_size - pos_smallest_number(b->stack,
		b->current_size);
	steps->big_up -= 1;
	steps->small_up -= 1;
	steps->big_down = pos_biggest_number(b->stack, b->current_size);
	steps->small_down = pos_smallest_number(b->stack, b->current_size);
}

int	find_up(t_steps *steps, t_stack *b, t_stack *a, int after_rotate)
{
	if (steps->small_up < steps->big_up && steps->small_up < steps->small_down)
	{
		move_up(steps->small_up, b, a);
		ft_putstr_fd("ra\n", 1);
		rotate_operator(a);
	}
	else if (steps->big_up < steps->small_up && steps->big_up < steps->big_down)
	{
		move_up(steps->big_up, b, a);
		after_rotate++;
	}
	return (after_rotate);
}

int	find_down(t_steps *steps, t_stack *b, t_stack *a, int after_rotate)
{
	if (steps->small_down < steps->big_down
		&& steps->small_down < steps->small_up)
	{
		move_down(steps->small_down, b, a);
		ft_putstr_fd("ra\n", 1);
		rotate_operator(a);
	}
	else if (steps->big_down < steps->small_down
		&& steps->big_down < steps->big_up)
	{
		move_down(steps->big_down, b, a);
		after_rotate++;
	}
	return (after_rotate);
}
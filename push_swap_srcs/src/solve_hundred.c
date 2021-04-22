/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 08:17:43 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/22 13:14:09 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_median(t_stack *a, t_stack *b, int median, int split)
{
	int	i;
	int	smallest;

	smallest = smallest_num(a->stack, a->current_size);
	i = 0;
	while (i < a->size)
	{
		if (split == 1 && a->stack[a->current_size - 1] <= median)
			push_operator(a, b);
		else if (split == 2 && a->stack[a->current_size -1] > median)
			push_operator(a, b);
		else
			rotate_operator(a);
		i++;
	}
}

int 	find_median(t_stack *a)
{
	int	quarter_len;
	int	array[a->current_size];
	int	median;
	int	i;

	median = 0;
	quarter_len = a->current_size / 4;
	i = 0;
	ft_bzero(array, a->current_size);
	while (i < a->current_size)
	{
		array[i] = a->stack[i];
		i++;
	}
	sort_array(array, a->current_size);
	median = array[quarter_len * 2];
	return (median);
}

void	move_up(int steps, t_stack *b, t_stack *a)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		rotate_operator(b);
		ft_putstr_fd("rb\n", 1);
		i++;
	}
	push_operator(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	move_down(int steps, t_stack *b, t_stack *a)
{
	int	i;

	i = 0;
	steps++;
	while (i < steps)
	{
		ft_putstr_fd("rrb\n", 1);
		reverse_rotate_operator(b);
		i++;
	}
	ft_putstr_fd("pa\n", 1);
	push_operator(b, a);
}

int	find_biggest_smallest(t_stack *b, t_stack *a)
{
	t_steps	steps;
	int		after_rotate;

	fill_steps(&steps, b);
	after_rotate = 0;
	if (steps.small_up < steps.small_down)
		after_rotate = find_up(&steps, b, a, after_rotate);
	else
		after_rotate = find_down(&steps, b, a, after_rotate);
	if (b->current_size == 1)
	{
		ft_putstr_fd("pa\n", 1);
		push_operator(b, a);
		after_rotate++;
	}
	return (after_rotate);
}

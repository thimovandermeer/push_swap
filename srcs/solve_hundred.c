/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 08:17:43 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/19 11:11:53 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_array(int *array, int len)
{
	int tmp;
	int	i;

	i = 0;
	tmp = 0;
	while(i < len - 1)
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

int		smallest_num(int *array, int len)
{
	int i = len - 1;
	int smallest_number = i;
	while(i)
	{
		if(array[i] <= smallest_number)
			smallest_number = array[i];
		i--;
	}
	return smallest_number;
}

void	push_median(t_stack *a, t_stack *b, int median, int split)
{

	int i;
	int smallest;
	smallest = smallest_num(a->stack, a->current_size);
	i = 0;
	while(i < a->size)
	{
		if (split == 1 && a->stack[a->current_size - 1] <= median)
			push_operator(a, b);
		else if (split == 2 && a->stack[a->current_size -1] > median)
			push_operator(a,b);
		else
			rotate_operator(a);
		i++;
	}
}

void	print_array(int *array, int len)
{
	int i = 0;
	while(i < len)
	{
		printf("%i = %i\n", i, array[i]);
		i++;
	}
}
// function to find the median
int 	find_median(t_stack *a)
{
	int quarter_len; 
	int array[a->current_size];
	int median;
	int i;

	median = 0;
	quarter_len = a->current_size / 4;
	i = 0;
	ft_bzero(array, a->current_size);
	while(i < a->current_size)
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
	int i;

	i = 0;
	while(i < steps)
	{
		rotate_operator(b);
		i++;
	}
	push_operator(b,a);
}
void	move_down(int steps, t_stack *b, t_stack *a)
{
	int i;

	i = 0;
	steps++;
	while(i < steps)
	{
		reverse_rotate_operator(b);
		i++;
	}
	push_operator(b, a);
}

int		find_biggest_smallest(t_stack *b, t_stack *a)
{
	int biggest_up;
	int smallest_up;
	int biggest_down;
	int smallest_down;
	int after_rotate;
	biggest_up = b->current_size - pos_biggest_number(b->stack, b->current_size);
	smallest_up = b->current_size - pos_smallest_number(b->stack, b->current_size);
	biggest_up -= 1;
	smallest_up -= 1;
	biggest_down = pos_biggest_number(b->stack, b->current_size);
	smallest_down = pos_smallest_number(b->stack, b->current_size);
	
	after_rotate = 0;
	if (smallest_up < biggest_up && smallest_up < smallest_down)
	{
		move_up(smallest_up, b, a);
		rotate_operator(a);
	}
	else if (biggest_up < smallest_up && biggest_up < biggest_down)
	{
		move_up(biggest_up, b, a);
		after_rotate++;
	}
	else if (smallest_down < biggest_down && smallest_down < smallest_up)
	{
		print_stack(b);
		move_down(smallest_down, b, a);
		rotate_operator(a);
	}
	else if (biggest_down < smallest_down && biggest_down < biggest_up)
	{
		print_stack(b);
		move_down(biggest_down, b,a);
		after_rotate++;
	}
	if (b->current_size == 1)
	{
		push_operator(b, a);
		after_rotate++;
	}
	return after_rotate;
}
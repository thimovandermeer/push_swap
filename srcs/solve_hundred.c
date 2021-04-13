/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 08:17:43 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/13 14:50:27 by thvan-de      ########   odam.nl         */
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

void	push_median(t_stack *a, t_stack *b, int i, int median)
{
	if (a->stack[a->current_size - 1] <= median)
		push_operator(a, b);
	else
		rotate_operator(a);
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
	printf("current_size = %zu\n", a->current_size);
	while(i < a->current_size)
	{
		array[i] = a->stack[i];
		i++;
		printf("deze ook niet?\n");
	}
	sort_array(array, a->current_size);
	median = array[quarter_len * 2];
	printf("median = %i\n", median);
	return (median);
}

// function to push to b until median is found


void	move_up(int distance, t_stack *b)
{
	if (distance > 0)
	{
		while(distance)
		{
			printf("move up\n");
			rotate_operator(b);
			distance--;
		}
	}
	
}

void 	move_down(int distance, t_stack *b)
{
	printf("distance = %i\n", distance);
	if(distance > 0)
	{
		while (distance)
		{
			// printf("movedown\n");
			reverse_rotate_operator(b);
			distance--;
		}
	}
}

void		find_biggest_smallest(t_stack *b, int j)
{
	int pos_biggest;
	int pos_smallest;
	int distance_big;
	int distance_small;
	
	pos_biggest = pos_biggest_number(b->stack, b->current_size - 1);
	pos_smallest = pos_smallest_number(b->stack, b->current_size - 1);
	printf("biggest = %i\n", pos_biggest);
	printf("smallest = %i\n", pos_smallest);
	while()
		move_up(j - pos_biggest, b);
	else
		move_down(j - pos_smallest, b);
}


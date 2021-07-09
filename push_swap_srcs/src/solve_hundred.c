/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 08:17:43 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/07/09 14:13:30 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
* 	This function calculates which numbers (inside the array) create the boundaries
*	between de differend quarters
*	It safes those boundaries for later use
*/


void 	find_quarters(t_stack *a, int *quarters, int num_quarters)
{
	int	quarter_size;
	int	i;
	int	*array;

	quarter_size = a->current_size / (num_quarters - 1);
	array = malloc(sizeof(int) * a->current_size);
	if (!array)
		exit(1);
	i = 0;
	ft_bzero(array, a->current_size);
	while (i < a->current_size)
	{
		array[i] = a->stack[i];
		i++;
	}
	sort_array(array, a->current_size);
	i = 0;
	while (i < (num_quarters - 1))
	{
		quarters[i] = array[quarter_size * i];
		i++;
	}
	quarters[i] = array[a->current_size - 1];
}

/*
*	This function calculates the distance to a number which falls between the boundarie of the quarter
*	The program is currently pushing. It checks how far a number is the buttom of the stack and
*	How far a number is from the top of the stack. It then checks which one is closer and start calculating
*	The steps which need to be taken to push it to the other stack
*/


void	find_biggest_smallest(t_stack *b, t_stack *a,
			int current_quarter, int *quarters)
{
	int		flag;
	int		step_up;
	int		step_down;
	int		smallest_number;

	flag = 1;
	step_up = 0;
	step_down = 0;
	smallest_number = smallest_num(a->stack, a->current_size);
	while (smallest_number <= quarters[current_quarter])
	{
		if (steps_up(a, current_quarter, quarters) != -1)
		{
			step_up = a->current_size - steps_up(a, current_quarter, quarters);
			step_up--;
		}
		else
			step_up = -1;
		step_down = steps_down(a, current_quarter, quarters);
		if (step_up > step_down)
			move_up(step_up, a, b, flag);
		else
			move_down(step_down, a, b, flag);
		smallest_number = smallest_num(a->stack, a->current_size);
	}
}

/*
* 	This function determines the positon of the biggest number currently in the stack
*/

int	pos_biggest_number(int *array, int size)
{
	int	i;
	int	biggest_number_pos;

	biggest_number_pos = 0;
	i = 0;
	while (i < size)
	{
		if (array[i] > array[biggest_number_pos])
			biggest_number_pos = i;
		i++;
	}
	return (biggest_number_pos);
}

/*
* 	This function determines the position of the smallest number currently in the stack
*/


int	pos_smallest_number(int *array, int size)
{
	int	i;
	int	smallest_number_pos;

	smallest_number_pos = 0;
	i = 0;
	while (i < size)
	{
		if (array[i] < array[smallest_number_pos])
			smallest_number_pos = i;
		i++;
	}
	return (smallest_number_pos);
}

/*
* 	This function checks if the current number which has to be pushed back is closer to the upper limit
*	Or to the lower limit it then determines if it should move up or down.
*/


void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	big_up;
	int	big_down;
	int	flag;

	flag = 0;
	while (b->current_size > 0)
	{
		big_up = b->current_size - pos_biggest_number
			(b->stack, b->current_size);
		big_up--;
		big_down = pos_biggest_number(b->stack, b->current_size);
		if (big_up < big_down)
		{
			flag = 2;
			move_up(big_up, b, a, flag);
		}
		else
		{
			flag = 2;
			move_down(big_down, b, a, flag);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 10:35:28 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/28 11:05:51 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

void	solve_three(t_stack *a)
{
	int biggest = pos_biggest_number(a->stack, a->current_size);
	int smallest = pos_smallest_number(a->stack, a->current_size);
	if(biggest == 0 && smallest == 1)
	{
		swap_operator(a);
		ft_putstr_fd("sa\n",1);
	}
	if(biggest == 2 && smallest == 0)
	{
		ft_putstr_fd("sa\n",1);
		swap_operator(a);
		ft_putstr_fd("rra\n",1);
		reverse_rotate_operator(a);
	}
	else if (biggest == 2 && smallest == 1)
	{
		rotate_operator(a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (smallest == 2 && biggest == 1)
	{
		ft_putstr_fd("sa\n",1);
		swap_operator(a);
		ft_putstr_fd("ra\n",1);
		rotate_operator(a);
	}
	else if (biggest == 1 && smallest == 0)
	{
		reverse_rotate_operator(a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	solve_five(t_stack *a, t_stack *b)
{
	ft_putstr_fd("pb\n", 1);
	ft_putstr_fd("pb\n", 1);
	push_operator(a,b);
	push_operator(a,b);
	solve_three(a);
	ft_putstr_fd("pa\n", 1);
	push_operator(b, a);
	if(a->stack[a->current_size - 1] > a->stack[0])
	{
		ft_putstr_fd("ra\n",1);
		rotate_operator(a);
	}
	ft_putstr_fd("pa\n", 1);
	push_operator(b, a);
	if(a->stack[a->current_size - 1] > a->stack[0])
	{
		rotate_operator(a);
		ft_putstr_fd("ra\n", 1);
	}
	// print_stack(a);
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

void	move_up(int steps, t_stack *b, t_stack *a)
{
	int	i;

	i = 0;
	// printf("steps = %i\n", 1);
	while (i < steps)
	{
		rotate_operator(b);
		ft_putstr_fd("rb\n", 1);
		i++;
	}
	push_operator(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	big_up;
	int big_down;
	while (b->current_size > 0)
	{
		big_up = b->current_size - pos_biggest_number
			(b->stack, b->current_size);
		big_up--;
		big_down = pos_biggest_number(b->stack, b->current_size);
		if (big_up < big_down)
			move_up(big_up, b, a);
		else
			move_down(big_down, b, a);
	}
}
	
void	solve_hundred(t_stack *a, t_stack *b)
{
	int			i;
	int			after_rotate;
	int			current_quarter;
	int			*quarters; // zometeen variabel maken

	after_rotate = 0;
	i = 0;
	current_quarter = 0;
	quarters = malloc(sizeof(int) * 4);
	find_quarters(a, quarters);
	while (i < a->current_size)
	{
		// first push numbers out of Q1
		if (a->stack[a->current_size - 1] <= quarters[current_quarter])
		{
			push_operator(a, b);
			ft_putstr_fd("pb\n", 1);
			i = 0;
		}
		else
		{
			rotate_operator(a);
			ft_putstr_fd("ra\n",1);
		}
		i++;
		if (i == a->current_size)
		{
			
			current_quarter++;
			if (current_quarter == 5)
			{
				// print_stack(b);
				push_back_to_a(a, b);
				break ;
			}
			i = 0;
		}
	}
}

void	solve(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (a->size <= 3)
			solve_three(a);
		else if (a->size <= 5)
			solve_five(a, b);
		else if (a->size <= 100)
			solve_hundred(a, b);
		return ;
	}
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		ret;
	int		*array;

	if (argc <= 1)
		return (1);
	// still need to check for duplicates
	if (check_inputs(argc, argv))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
	// save inputs
	a.size = argc - 1;
	if (save_inputs(argv, &a, &b) == -1)
		return (1);
	// check if sorted
	// print_stack(&a);

	solve_hundred(&a, &b);
	// print_stack(&a);
	// print_stack(&b);
	// solve(&a, &b);
}
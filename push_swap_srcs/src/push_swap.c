/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 10:35:28 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/22 14:03:44 by thvan-de      ########   odam.nl         */
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

void	solve_hundred(t_stack *a, t_stack *b)
{
	int	i;
	int	median;
	int	after_rotate;
	int	split;

	after_rotate = 0;
	i = 0;
	split = 1;
	median = find_median(a);
	while (a->stack)
	{
		push_median(a, b, median, split);
		while (b->current_size > 0)
			after_rotate += find_biggest_smallest(b, a);
		while (after_rotate)
		{
			ft_putstr_fd("ra\n", 1);
			rotate_operator(a);
			after_rotate--;
		}
		split++;
		if (split == 3)
			break ;
	}
}

void	solve_big_stack()
{
	
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
		else
			solve_big_stack();
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
		ft_putstr_fd("Error during checking inputs", 1);
		exit(1);
	}
	// save inputs
	a.size = argc - 1;
	if (save_inputs(argv, &a, &b) == -1)
		return (1);
	// check if sorted
	// print_stack(&a);
	// print_stack(&a);
	solve_hundred(&a, &b);
	// print_stack(&a);
	// solve(&a, &b);
}
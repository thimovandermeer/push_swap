/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 10:35:28 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/29 14:31:25 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_hundred(t_stack *a, t_stack *b)
{
	int	current_quarter;
	int	*quarters;
	int	num_quarters;

	num_quarters = 5;
	current_quarter = 1;
	quarters = malloc(sizeof(int) * num_quarters);
	if (quarters == NULL)
		exit(1);
	find_quarters(a, quarters, num_quarters);
	while (a->current_size > 0)
	{
		find_biggest_smallest(b, a, current_quarter, quarters);
		current_quarter++;
		if (current_quarter == 5)
			break ;
	}
	push_back_to_a(a, b);
}

void	solve_big_stack(t_stack *a, t_stack *b)
{
	int	current_quarter;
	int	*quarters;
	int	num_quarters;

	num_quarters = 13;
	current_quarter = 1;
	quarters = malloc(sizeof(int) * num_quarters);
	if (quarters == NULL)
		exit(1);
	find_quarters(a, quarters, num_quarters);
	while (a->current_size > 0)
	{
		find_biggest_smallest(b, a, current_quarter, quarters);
		current_quarter++;
		if (current_quarter == num_quarters)
			break ;
	}
	push_back_to_a(a, b);
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
			solve_big_stack(a, b);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		ret;
	int		*array;

	if (argc <= 1)
		return (1);
	if (check_inputs(argc, argv))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
	a.size = argc - 1;
	if (save_inputs(argv, &a, &b) == -1)
		return (1);
	solve(&a, &b);
}

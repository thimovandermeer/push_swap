/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 10:49:16 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/12 10:26:24 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_inputs(int num_args, char **arguments)
{
	int	i;

	i = 1;
	while (i < num_args)
	{
		if (is_all_num(arguments[i]))
			return (1);
		if (is_integer(arguments[i]))
			return (1);
		i++;
	}
	return (0);
}

int	save_inputs(char **arguments, t_stack *a, t_stack *b)
{
	int	i;
	int	res;
	int	j;

	i = 1;
	b->size = a->size;
	a->current_size = 0;
	b->current_size = a->current_size;
	a->stack = malloc(sizeof(int) * a->size);
	b->stack = malloc(sizeof(int) * b->size);
	if (!b->stack || !a->stack)
		return (-1);
	ft_bzero(a->stack, a->size);
	ft_bzero(b->stack, b->size);
	j = 0;
	while (arguments[i])
	{
		a->stack[j] = ft_atoi(arguments[i]);
		a->current_size++;
		i++;
		j++;
	}
	return (0);
}

void	read_instructions(t_stack *a, t_stack *b)
{
	char	*operator;

	while (get_next_line(STDIN_FILENO, &operator))
	{
		if (!ft_strcmp(operator, "STOP"))
			break ;
		if (!check_operator(a, b, operator))
		{
			ft_putstr_fd("Illegal instruction", 1);
			exit(1);
		}
		print_stack(a);
		print_stack(b);
	}
}

void	clean_stacks(int **a, int **b)
{
	free(*a);
	free(*b);
}

int	main(int argc, char **argv)
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
	a.size = argc;
	if (save_inputs(argv, &a, &b) == -1)
		return (1);
	read_instructions(&a, &b);
	a.size = argc - 1;
	ret = is_sorted(&a);
	if (ret == 1)
		ft_putstr_fd("OK\n", 1 );
	else
		ft_putstr_fd("KO\n", 1 );
	clean_stacks(&a.stack, &b.stack);
}

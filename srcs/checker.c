/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 10:49:16 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/13 08:20:21 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	read_instructions(t_stack *a, t_stack *b)
{
	char	*operator;
	print_stack(a);
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
	a.size = argc - 1;
	printf("a.size = %zu\n", a.size);
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

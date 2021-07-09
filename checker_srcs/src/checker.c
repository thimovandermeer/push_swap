/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 10:49:16 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/07/09 13:53:28 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_srcs/include/checker.h"

/*
* 	This function creates the operator from the terminal. Using get_next_line we retrieve the operator.
*	The only check being done here is for STOP this is for debugging purposes.
*/

void	read_instructions(t_stack *a, t_stack *b)
{
	char	*operator;

	while (get_next_line(STDIN_FILENO, &operator))
	{
		if (!ft_strcmp(operator, "STOP") || ft_strlen(operator) == 0)
			break ;
		if (!check_operator(a, b, operator))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
	}
}

/*
* 	This function cleans the two stacks
*/

void	clean_stacks(int **a, int **b)
{
	free(*a);
	free(*b);
}

/*
* 	Main function in which all actions are being orchestrated
*/


int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		ret;

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
	read_instructions(&a, &b);
	a.size = argc - 1;
	ret = is_sorted(&a);
	if (ret == 1)
		ft_putstr_fd("OK\n", 1 );
	else
		ft_putstr_fd("KO\n", 1 );
	clean_stacks(&a.stack, &b.stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 10:04:39 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/12 07:09:55 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->current_size)
	{
		printf("%i = %i\n", i, a->stack[i]);
		i++;
	}
	printf("Full stack has been printed\n");
}

int	is_all_num(char *arguments)
{
	int	i;

	i = 0;
	while (i < ft_strlen(arguments))
	{
		if (!ft_isdigit(arguments[i]))
		{
			ft_putstr_fd("Is not a number\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_integer(char *arguments)
{
	int	i;
	int	res;

	i = 0;
	while (i < ft_strlen(arguments))
	{
		res = ft_atoi(arguments);
		if (res == -1)
		{
			ft_putstr_fd("Number is not an integer\n", 1);
			return (1);
		}
		if (res < 0)
		{
			ft_putstr_fd("Number is smaller than 0 \n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->size != a->current_size)
		return (0);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

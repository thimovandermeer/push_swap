/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_operators.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 13:40:48 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/12 10:25:32 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_swap_operator(const char *operator, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operator, "sa"))
	{
		swap_operator(a);
		return (1);
	}
	if (!ft_strcmp(operator, "sb"))
	{
		swap_operator(b);
		return (1);
	}	
	if (!ft_strcmp(operator, "ss"))
	{
		swap_operator(b);
		swap_operator(a);
		return (1);
	}
	return (0);
}

int	check_push_operator(const char *operator, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operator, "pa"))
	{
		push_operator(b, a);
		return (1);
	}
	if (!ft_strcmp(operator, "pb"))
	{
		push_operator(a, b);
		return (1);
	}
	return (0);
}

int	check_rotate_operator(const char *operator, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operator, "ra"))
	{
		rotate_operator(a);
		return (1);
	}
	if (!ft_strcmp(operator, "rb"))
	{
		rotate_operator(b);
		return (1);
	}
	if (!ft_strcmp(operator, "rr"))
	{
		rotate_operator(a);
		rotate_operator(b);
		return (1);
	}
	return (0);
}

int	check_reverse_operator(const char *operator, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operator, "rra"))
	{
		reverse_rotate_operator(a);
		return (1);
	}
	if (!ft_strcmp(operator, "rrb"))
	{
		reverse_rotate_operator(b);
		return (1);
	}
	if (!ft_strcmp(operator, "rrr"))
	{
		reverse_rotate_operator(a);
		reverse_rotate_operator(b);
		return (1);
	}
	return (0);
}

int	check_operator(t_stack *a, t_stack *b, const char *operator)
{
	if (check_swap_operator(operator, a, b))
		return (1);
	if (check_push_operator(operator, a, b))
		return (1);
	if (check_rotate_operator(operator, a, b))
		return (1);
	if (check_reverse_operator(operator, a, b))
		return (1);
	return (0);
}

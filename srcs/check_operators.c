/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_operators.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 13:40:48 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/06 15:15:00 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap_operator(const char *operator, t_stack *a, t_stack *b)
{
	if(ft_strcmp(operator, "sa"))
	{
		swap_operator(a);
		return 1;
	}
	if(ft_strcmp(operator, "sb"))
	{
		swap_operator(b);
		return 1;
	}	
	if(ft_strcmp(operator, "ss"))
	{
		swap_operator(b);
		swap_operator(a);
		return 1;
	}
	return 0;
}

int check_push_operator(const char *operator, t_stack *a, t_stack *b)
{
	if(ft_strcmp(operator, "pa"))
	{
		push_operator(b, a);
		return 1;
	}
	if(ft_strcmp(operator, "pb"))
	{
		push_operator(a, b);
		return 1;
	}
	return 0;
}

int	check_rotate_operator(const char *operator, t_stack *a, t_stack *b)
{
	if(ft_strcmp(operator, "ra"))
	{
		// do_ra
		return 1;
	}
	if(ft_strcmp(operator, "rb"))
	{
		// do_rb
		return 1;
	}
	if(ft_strcmp(operator, "rr"))
	{
		// do_ra
		// do_rb
		return 1;
	}
	return 0;
}

int check_reverse_operator(const char *operator, t_stack *a, t_stack *b)
{
	if(ft_strcmp(operator, "rra"))
	{
		// do_rra
		return 1;
	}
	if(ft_strcmp(operator, "rrb"))
	{
		// do_rrb
		return 1;
	}
	if(ft_strcmp(operator, "rrr"))
	{
		// do_rrr
		return 1;
	}
	return 0;
}

int check_operator(t_stack *a, t_stack *b, const char *operator)
{
	// check for swap operators
	if (check_swap_operator(operator, a, b))
		return 1;
	// check for push operators
	if (check_push_operator(operator, a, b))
		return 1;
	// check for rotate operators
	if (check_rotate_operator(operator, a, b))
		return 1;
	// check for reverse operators
	if (check_reverse_operator(operator, a, b))
		return 1;
	return 0;
}


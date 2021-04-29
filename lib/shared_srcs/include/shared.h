/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 08:40:48 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/29 15:40:09 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include <unistd.h>
# include <stdlib.h>
# include "/Users/thimovandermeer/Desktop/Codam projecten/push_swap/lib/libft/libft.h"
typedef struct s_stack
{
	size_t	size;
	size_t	current_size;
	int		*stack;
}				t_stack;

/*
*  Operator functions
*/

void	swap_elems(int *old_top, int *new_top);
void	swap_operator(t_stack *stack);
void	push_operator(t_stack *giver, t_stack *receiver);
void	reverse_rotate_operator(t_stack *a);
void	rotate_operator(t_stack *a);

/*
*  Util functions
*/

int		check_duplicate(int *array, int len, int number);
int		save_inputs(char **arguments, t_stack *a, t_stack *b);
int		check_inputs(int num_args, char **arguments);
int		is_all_num(char *arguments);
int		is_integer(char *arguments);

/*
*  Util2 functions
*/

int		is_sorted(t_stack *a);
void	sort_array(int *array, int len);

#endif 
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 13:06:12 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/06 14:58:11 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "/Users/thimovandermeer/Desktop/Codam projecten/push_swap/libft/libft.h"
#include "/Users/thimovandermeer/Desktop/Codam projecten/push_swap/get_next_line/get_next_line.h"

typedef struct s_stack
{
	size_t 	size;
	size_t 	current_size;
	int		*stack;
}				t_stack;

/*
*  Check Operator functions
*/

int	check_swap_operator(const char *operator, t_stack *a, t_stack *b);
int check_push_operator(const char *operator, t_stack *a, t_stack *b);
int	check_rotate_operator(const char *operator, t_stack *a, t_stack *b);
int check_reverse_operator(const char *operator, t_stack *a, t_stack *b);
int check_operator(t_stack *a, t_stack *b, const char *operator);

/*
*  Operator functions
*/

void	swap_elems(int *old_top, int *new_top);
void	swap_operator(t_stack *stack);
void	push_operator(t_stack *giver, t_stack *receiver);
void	rotate_operator();
void	reverse_rotate_operator();
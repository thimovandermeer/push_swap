/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 11:25:52 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/22 14:00:34 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "/Users/thimovandermeer/Desktop/Codam projecten/push_swap/lib/shared_srcs/include/shared.h"

/*
*  push_swap functions
*/

int		pos_biggest_number(int *array, int size);
int		pos_smallest_number(int *array, int size);
void	solve_three(t_stack *a);
void	solve_five(t_stack *a, t_stack *b);
void	solve_hundred(t_stack *a, t_stack *b);
void	solve_big_stack(void);
void	solve(t_stack *a, t_stack *b);

/*
*  solve hundred functions
*/

void	push_median(t_stack *a, t_stack *b, int median, int split);
int		find_median(t_stack *a);
void	move_up(int steps, t_stack *b, t_stack *a);
void	move_down(int steps, t_stack *b, t_stack *a);
int		find_biggest_smallest(t_stack *b, t_stack *a);

/*
*  solve hundred util functions
*/

void	sort_array(int *array, int len);
int		smallest_num(int *array, int len);
void	fill_steps(t_steps *steps, t_stack *b);
int		find_up(t_steps *steps, t_stack *b, t_stack *a, int after_rotate);
int		find_down(t_steps *steps, t_stack *b, t_stack *a, int after_rotate);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 11:25:52 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/05/03 11:25:00 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/shared_srcs/include/shared.h"
# include <stdio.h> //

/*
*  push_swap functions
*/

void	solve_hundred(t_stack *a, t_stack *b);
void	solve_big_stack(t_stack *a, t_stack *b);
void	solve(t_stack *a, t_stack *b);
int		main(int argc, char **argv);

/*
*  small_solve _functions
*/

void	solve_three_part_two(t_stack *a, int biggest, int smallest);
void	solve_three(t_stack *a);
void	solve_five(t_stack *a, t_stack *b);
void	solve_five_push_big_small(t_stack *a, t_stack *b);

/*
*  solve hundred functions
*/

void	find_quarters(t_stack *a, int *quarters, int num_quarters);
void	find_biggest_smallest(t_stack *b, t_stack *a,
			int current_quarter, int *quarters);
int		pos_biggest_number(int *array, int size);
int		pos_smallest_number(int *array, int size);
void	push_back_to_a(t_stack *a, t_stack *b);

/*
*  solve hundred util functions
*/

int		smallest_num(int *array, int len);
void	move_down(int steps, t_stack *b, t_stack *a, int flag);
void	move_up(int steps, t_stack *b, t_stack *a, int flag);
int		steps_down(t_stack *a, int current_quarter, int *quarters);
int		steps_up(t_stack *a, int current_quarter, int *quarters);
#endif
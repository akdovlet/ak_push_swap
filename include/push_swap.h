/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:18:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/19 00:26:38 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_val
{
	int		size;
	long	min;
	long	max;
	int		amedian;
	int		bmedian;
	long	median;
}	t_val;

/* ************************************************************************** */
/* ******************************array.c************************************* */
/* ************************************************************************** */

// creates a copy of the stack in an array
long	*copy_stack(t_list *lst, int size);

/* ************************************************************************** */
/* ******************************chechen_sort.c****************************** */
/* ************************************************************************** */

// PUts a hit on a target
void	assign_target(t_list **hitter, t_list **target, t_val *val);
// Brings the package up top
void	top_up(t_list **stack_a, t_list **stack_b, t_val *val);
// Precomputes the stack. Does all the math and shit
void	pre_compute(t_list **stack_a, t_list **stack_b, t_val *val);
// Stop asking questions
void	chechen_sort(t_list **stack_a, t_list **stack_b, t_val *val);

/* ************************************************************************** */
/* ******************************error_check.c******************************* */
/* ************************************************************************** */

// Frees the list and the array if bin is given
void	*clear_free(t_list **lst, long *tab, int bin);
// Checks for duplicates in the array
int		duplicate_check(long *arr, int size);
// Checks for any characters I deem unaceptable, resulting in an Error
int		char_check(char c);
// Driver code for all the parsing, stack creation and error management
long	*parse_and_check(t_list **lst, char **av, int ac, t_val *val);

/* ************************************************************************** */
/* ******************************int.c*************************************** */
/* ************************************************************************** */

// Returns the smallest of the two numbers
int		smallest(int a, int b);
// Returns the median of the array
long	median(long *tab, int size);
// Converts a string to a long but also checks for int over/underflows 
//as well as any other errors
long	ak_atol(const char *nptr, t_val *val);

/* ************************************************************************** */
/* ******************************intel_gathering.c*************************** */
/* ************************************************************************** */

// Finds the largest and smallest number in a stack
void	set_min_max(t_list **stack, t_val *val);
// Finds the smallest node in the stack
t_list	*lowest(t_list *lst);
// Finds the cheapest node to move to the top
t_list	*cheapest(t_list **stack);
// counts how much it costs to put a node at the top and 
// assigns an index and a median to the stack_a
void	a_cost_count(t_list **stack_a, t_val *val);
// counts how much it costs to put a node at the top and
// assigns an index and a median to the stack_b
void	b_cost_count(t_list **stack_b, t_val *val);

/* ************************************************************************** */
/* ******************************jade.c************************************** */
/* ************************************************************************** */

// Returns the target node for a given number, which is the closest number
t_list	*target_node(long n, t_list **stack, t_val *val);
// Rotates the stack_a to the correct position, so that the stack is sorted
void	finish_rotate_a(t_list **stack_a, t_list *low, t_val *val);

/* ************************************************************************** */
/* ******************************parsing.c*********************************** */
/* ************************************************************************** */

// Frees the list
void	ps_lstclear(t_list **lst, void (*del)(void *));
// Parses the arguments and creates the stack
int		parse_av(t_list **lst, char *av, t_val *val);
// Creates the stack
int		stack_creation(t_list **lst, char **av, int ac, t_val *val);

/* ************************************************************************** */
/* ******************************quicksort.c********************************* */
/* ************************************************************************** */

// Simple swap function
void	ft_swap(long *a, long *b);
//	Quick sort algorithm
long	partition(long *arr, int low, int high);
//	Quick sort algorithm
void	ak_quicksort(long *arr, int low, int high);

/* ************************************************************************** */
/* ******************************solver.c************************************ */
/* ************************************************************************** */

// Will call the right sorting algorithm given the size of the stack
void	solver(t_list **stack_a, t_list **stack_b, t_val *val, int size);
// Sorts the smallest stack
void	sort_two(t_list **stack_a);
// Sorts three numbers
void	sort_three(t_list **stack_a);
// Checks if the stack is sorted
int		is_sorted(t_list *stack_a);
// Finds the highest number in the stack
t_list	*highest(t_list *lst);

/* ************************************************************************** */
/* ******************************push.c************************************** */
/* ************************************************************************** */

// push a - take the first element at the top of b and put 
// it at the top of a. Do nothing if b is empty.
void	push_a(t_list **a, t_list **b, int bin);
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(t_list **a, t_list **b, int bin);

/* ************************************************************************** */
/* ******************************reverse_rotate.c**************************** */
/* ************************************************************************** */

// Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	reverse_rotate_a(t_list **a, int bin);
// Shift down all elements of stack b by 1. 
// The last element becomes the first one.
void	reverse_rotate_b(t_list **b, int bin);
// rra and rrb at the same time
void	reverse_rotate_all(t_list **a, t_list **b, int bin);

/* ************************************************************************** */
/* *****************************rotate.c************************************* */
/* ************************************************************************** */

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(t_list **a, int bin);
// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate_b(t_list **b, int bin);
// ra and rb at the same time
void	rotate_all(t_list **a, t_list **b, int bin);

/* ************************************************************************** */
/* *****************************swap.c*************************************** */
/* ************************************************************************** */

// Swap the first 2 elements at the top of stack a.
void	swap_a(t_list **lst, int bin);
// Swap the first 2 elements at the top of stack b.
void	swap_b(t_list **lst, int bin);
// sa and sb at the same time
void	swap_a_b(t_list **a, t_list **b, int bin);

#endif

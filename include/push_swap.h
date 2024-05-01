/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:18:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/05/01 17:54:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

//	My stack as a linked list, each node contains information about itself 
//	as well as a pointer to its target
typedef struct s_stack
{
	int				nbr;
	int				index;
	int				moves;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

// Control structure, contains general information about both stacks
typedef struct s_val
{
	t_stack		*min;
	t_stack		*max;
	int			asize;
	int			bsize;
	int			amedian;
	int			bmedian;
	int			median;
}	t_val;


/* ************************************************************************** */
/* ******************************array.c************************************* */
/* ************************************************************************** */

// creates a copy of the stack in an array
int		*copy_stack(t_stack *lst, int size);

/* ************************************************************************** */
/* ******************************chechen_sort.c****************************** */
/* ************************************************************************** */

// Puts a hit on a target
void	assign_target(t_stack **hitter, t_stack **target, t_val *val);
// Brings the package up top
void	top_up(t_stack **stack_a, t_stack **stack_b, t_val *val);
// Precomputes the stack. Does all the math and shit
void	pre_compute(t_stack **stack_a, t_stack **stack_b, t_val *val);
// Stop asking questions
void	chechen_sort(t_stack **stack_a, t_stack **stack_b, t_val *val);

/* ************************************************************************** */
/* ******************************error_check.c******************************* */
/* ************************************************************************** */

// Frees the list and the array if bin is given
void	*clear_free(t_stack **lst, int *tab, bool bin);
// Checks for duplicates in the array
bool	duplicate_check(int *arr, int size);
// Checks for any characters I deem unaceptable, resulting in an Error
bool	char_check(char c);
// Driver code for all the parsing, stack creation and error management
bool	parse_and_check(t_stack **lst, char **av, int ac, t_val *val);
// Checks if I have reached the potential beggining of an int to extract
bool	start_extraction(char c);

/* ************************************************************************** */
/* ******************************int.c*************************************** */
/* ************************************************************************** */

// Returns the smallest of two numbers
int		smallest(int a, int b);
// Returns the biggest of two numbers
int		biggest(int a, int b);
// Returns the median of the array
int		median(int *tab, int size);
// Converts a string to an int but also checks for int over/underflows 
//as well as any other errors
int		ak_atoi(const char *nptr, int *i);

/* ************************************************************************** */
/* ******************************intel_gathering.c*************************** */
/* ************************************************************************** */

// Finds the largest and smallest number in a stack
void	set_min_max(t_stack **stack, t_val *val);
// Finds the smallest node in the stack
t_stack	*lowest(t_stack *lst);
// Finds the cheapest node to move to the top
t_stack	*cheapest(t_stack **stack, t_val * val);
// counts how much it costs to put a node at the top and 
// assigns an index and a median to the stack_a
void	a_cost_count(t_stack **stack_a, t_val *val);
// counts how much it costs to put a node at the top and
// assigns an index and a median to the stack_b
void	b_cost_count(t_stack **stack_b, t_val *val);

/* ************************************************************************** */
/* ******************************jade.c************************************** */
/* ************************************************************************** */

// Returns the target node for a given number, which is the closest number
t_stack	*target_node(int n, t_stack **stack, t_val *val);
// Rotates the stack_a to the correct position, so that the stack is sorted
void	finish_rotate_a(t_stack **stack_a, t_stack *low, t_val *val);

/* ************************************************************************** */
/* ******************************lst_functions.c***************************** */
/* ************************************************************************** */

// Same as ft_lstsize
int		ft_stacksize(t_stack *stack);
// Same as ft_lstadd_back
void	ft_stackadd_back(t_stack **stack, t_stack *new);
// Same as ft_lstnew, only difference: sets values to 0 or NULL
t_stack	*ft_stacknew(int nbr);
// Same as ft_lstlast
t_stack	*ft_stacklast(t_stack *stack);
// Same as ft_lstclear, except we don't apply del on the content, we only free
void	ft_stackclear(t_stack **stack);

/* ************************************************************************** */
/* ******************************parsing.c*********************************** */
/* ************************************************************************** */

// Parses the arguments and creates the stack
bool	parse_av(t_stack **lst, char *av, t_val *val);
// Creates the stack
bool	stack_creation(t_stack **lst, char **av, int ac, t_val *val);

/* ************************************************************************** */
/* ******************************quicksort.c********************************* */
/* ************************************************************************** */

// Simple swap function
void	ft_swap(int *a, int *b);
//	Quick sort algorithm
int		partition(int *arr, int low, int high);
//	Quick sort algorithm
void	ak_quicksort(int *arr, int low, int high);

/* ************************************************************************** */
/* ******************************solver.c************************************ */
/* ************************************************************************** */

// Will call the right sorting algorithm given the size of the stack
void	solver(t_stack **stack_a, t_stack **stack_b, t_val *val, int size);
// Sorts the smallest stack
void	sort_two(t_stack **stack_a);
// Sorts three numbers
void	sort_three(t_stack **stack_a);
// Checks if the stack is sorted
int		is_sorted(t_stack *stack_a);
// Finds the highest number in the stack
t_stack	*highest(t_stack *lst);

/* ************************************************************************** */
/* ******************************push.c************************************** */
/* ************************************************************************** */

// push a - take the first element at the top of b and put 
// it at the top of a. Do nothing if b is empty.
void	push_a(t_stack **a, t_stack **b, int bin);
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(t_stack **a, t_stack **b, int bin);

/* ************************************************************************** */
/* ******************************reverse_rotate.c**************************** */
/* ************************************************************************** */

// Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	reverse_rotate_a(t_stack **a, int bin);
// Shift down all elements of stack b by 1. 
// The last element becomes the first one.
void	reverse_rotate_b(t_stack **b, int bin);
// rra and rrb at the same time
void	reverse_rotate_all(t_stack **a, t_stack **b, int bin);

/* ************************************************************************** */
/* *****************************rotate.c************************************* */
/* ************************************************************************** */

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(t_stack **a, int bin);
// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate_b(t_stack **b, int bin);
// ra and rb at the same time
void	rotate_all(t_stack **a, t_stack **b, int bin);

/* ************************************************************************** */
/* *****************************swap.c*************************************** */
/* ************************************************************************** */

// Swap the first 2 elements at the top of stack a.
void	swap_a(t_stack **lst, int bin);
// Swap the first 2 elements at the top of stack b.
void	swap_b(t_stack **lst, int bin);
// sa and sb at the same time
void	swap_a_b(t_stack **a, t_stack **b, int bin);

#endif

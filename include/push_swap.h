/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:18:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/17 19:18:52 by akdovlet         ###   ########.fr       */
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
}	t_val;

int		char_check(char c);
void	ps_lstclear(t_list **lst, void (*del)(void *));
int		parse_av(t_list **lst, char *av, t_val *val);
int		stack_creation(t_list **lst, char **av, int ac, t_val *val);
void	swap_a(t_list **lst, int bin);
void	swap_b(t_list **lst, int bin);
void	swap_a_b(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a, int bin);
void	rotate_b(t_list **a, int bin);
void	rotate_all(t_list **a, t_list **b);
void	reverse_rotate_a(t_list **a, int bin);
void	reverse_rotate_b(t_list **b, int bin);
void	reverse_rotate_all(t_list **a, t_list **b);
long	*copy_stack(t_list *lst, int size);
void	ak_quicksort(long *arr, int low, int high);
int		duplicate_check(long *arr, int size);
void	print_array(long *tab, int size);
void	indexing(t_list *lst, long *tab, int size);
long	*parse_and_check(t_list **lst, char **av, int ac, t_val *val);
void	solver(t_list **stack_a, t_list **stack_b, t_val *val, int size);
void	sort_two(t_list **lst);
void	sort_three(t_list **lst);
long	ak_atol(const char *nptr, t_val *val);
int		is_sorted(t_list *lst);
t_list	*highest(t_list *lst);
void	sort(t_list **stack_a, t_list **stack_b, t_val *val);
int		smallest(int a, int b);
void	b_lst_indexing(t_list **stack_b, t_val *val);
void	a_lst_indexing(t_list **stack_a, t_val *val);
long	median(long *tab, int size);
void	finish_rotate_b(t_list **stack_b, t_list *high, t_val *val);
void	finish_rotate_a(t_list **stack_a, t_list *low, t_val *val);
void	print_list(t_list *lst);
void	print_b(t_list *lst);
t_list	*target_node(long n, t_list **stack_b, t_val *val);
void	set_min_max(t_list **stack_b, t_val *val);
void	a_cost_count(t_list **stack_a, t_val *val);
void	b_cost_count(t_list **stack_b, t_val *val);
void	rotate_stacks(t_list **stack_a, t_list **stack_b, t_val *val);
void	chechen_sort(t_list **stack_a, t_list **stack_b, t_val *val);
t_list	*cheapest(t_list **stack);
t_list	*lowest(t_list *lst);
void	assign_target(t_list **hitter, t_list **target, t_val *val);
t_list	*cheapest_q1(t_list **stack);
t_list	*cheapest_q2(t_list *stack);
t_list	*cheapest_q3(t_list *stack);
t_list	*cheapest_q4(t_list *stack);

void	pre_compute(t_list **stack_a, t_list **stack_b, t_val *val);

#endif

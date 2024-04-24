/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chechen_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:01:45 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/24 15:30:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_target(t_list **hitter, t_list **target, t_val *val)
{
	t_list	*soldier;

	soldier = *hitter;
	while (soldier)
	{
		soldier->target = target_node((long)soldier->content, target, val);
		soldier = soldier->next;
	}
}

void	top_up(t_list **stack_a, t_list **stack_b, t_val *val)
{
	int		i;
	int		j;
	t_list	*cheap;

	cheap = cheapest(stack_b);
	j = cheap->index;
	i = cheap->target->index;
	while ((*stack_b != cheap && *stack_a != cheap->target) && \
			(i > val->amedian && j > val->bmedian))
		reverse_rotate_all(stack_a, stack_b, 1);
	while ((*stack_b != cheap && *stack_a != cheap->target) && \
			(i <= val->amedian && j <= val->bmedian))
		rotate_all(stack_a, stack_b, 1);
	while (*stack_b != cheap && cheap->index > val->bmedian)
		reverse_rotate_b(stack_b, 1);
	while (*stack_b != cheap && cheap->index <= val->bmedian)
		rotate_b(stack_b, 1);
	while (cheap->target != *stack_a && cheap->target->index > val->amedian)
		reverse_rotate_a(stack_a, 1);
	while (cheap->target != *stack_a && cheap->target->index <= val->amedian)
		rotate_a(stack_a, 1);
}

void	pre_compute(t_list **stack_a, t_list **stack_b, t_val *val)
{
	set_min_max(stack_a, val);
	a_cost_count(stack_a, val);
	b_cost_count(stack_b, val);
	assign_target(stack_b, stack_a, val);
}

void	chechen_sort(t_list **stack_a, t_list **stack_b, t_val *val)
{
	int		len;
	t_list	*low;

	len = ft_lstsize(*stack_a);
	while (len-- > 3)
	{
		push_b(stack_a, stack_b, 1);
		if ((long)(*stack_b)->content > val->median)
			rotate_b(stack_b, 1);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pre_compute(stack_a, stack_b, val);
		top_up(stack_a, stack_b, val);
		push_a(stack_a, stack_b, 1);
	}
	a_cost_count(stack_a, val);
	low = lowest(*stack_a);
	if (*stack_a != low)
		finish_rotate_a(stack_a, low, val);
}

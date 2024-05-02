/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chechen_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:01:45 by akdovlet          #+#    #+#             */
/*   Updated: 2024/05/02 20:36:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_target(t_stack **hitter, t_stack **target, t_val *val)
{
	t_stack	*soldier;

	soldier = *hitter;
	while (soldier)
	{
		soldier->target = target_node(soldier->nbr, target, val);
		soldier = soldier->next;
	}
}

void	top_up(t_stack **stack_a, t_stack **stack_b, t_val *val)
{
	int		ci;
	int		ti;
	t_stack	*cheap;

	cheap = cheapest(stack_b);
	ci = cheap->index;
	ti = cheap->target->index;
	while ((*stack_b != cheap && *stack_a != cheap->target) && \
			(ci > val->bmedian && ti > val->amedian))
		reverse_rotate_all(stack_a, stack_b, 1);
	while ((*stack_b != cheap && *stack_a != cheap->target) && \
			(ci <= val->bmedian && ti <= val->amedian))
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

void	pre_compute(t_stack **stack_a, t_stack **stack_b, t_val *val)
{
	assign_target(stack_b, stack_a, val);
	a_cost_count(stack_a, val);
	b_cost_count(stack_b, val);
}

void	update_min_max(t_stack *stack_a, t_val *val)
{
	if (stack_a->nbr > val->max->nbr)
		val->max = stack_a;
	if (stack_a->nbr < val->min->nbr)
		val->min = stack_a;
}

void	chechen_sort(t_stack **stack_a, t_stack **stack_b, t_val *val)
{
	while (val->asize-- > 3)
	{
		push_b(stack_a, stack_b, 1);
		val->bsize += 1;
		if ((*stack_b)->nbr > val->median)
			rotate_b(stack_b, 1);
	}
	sort_three(stack_a);
	set_min_max(stack_a, val);
	while (*stack_b)
	{
		pre_compute(stack_a, stack_b, val);
		top_up(stack_a, stack_b, val);
		push_a(stack_a, stack_b, 1);
		val->asize += 1;
		val->bsize -= 1;
		update_min_max(*stack_a, val);
	}
	a_cost_count(stack_a, val);
	if (*stack_a != val->min)
		finish_rotate_a(stack_a, val->min, val);
}

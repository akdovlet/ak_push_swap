/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chechen_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:01:45 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/17 19:25:35 by akdovlet         ###   ########.fr       */
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

void	assign_qtarget(t_list **hitter, t_list **target, t_val *val)
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
	while ((*stack_b != cheap && *stack_a != cheap->target) && (i > val->amedian && j > val->bmedian))
		reverse_rotate_all(stack_a, stack_b);
	while ((*stack_b != cheap && *stack_a != cheap->target) && (i <= val->amedian && j <= val->bmedian))
		rotate_all(stack_a, stack_b);
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

void	quarter(t_list *stack, int quart)
{
	while (stack)
	{
		if (stack->end <= quart)
			stack->q1 = 1;
		else if (stack->end <= quart * 2)
			stack->q2 = 1;
		else if (stack->end <= quart * 3)
			stack->q3 = 1;
		else
			stack->q4 = 1;
		stack = stack->next;
	}
}

t_list	*cheapest_q1(t_list **stack)
{
	t_list	*cheapest;
	t_list	*tmp;

	tmp = *stack;
	cheapest = NULL;
	while (tmp)
	{
		if (tmp->q1)
		{
			if (!cheapest)
				cheapest = tmp;
			else if (tmp->moves < cheapest->moves)
				cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

t_list	*cheapest_q2(t_list *stack)
{
	t_list	*cheapest;

	cheapest = NULL;
	while (stack)
	{
		if (stack->q2)
		{
			if (!cheapest)
				cheapest = stack;
			else if (stack->moves < cheapest->moves)
				cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}

t_list	*cheapest_q3(t_list *stack)
{
	t_list	*cheapest;

	cheapest = NULL;
	while (stack)
	{
		if (stack->q3)
		{
			if (!cheapest)
				cheapest = stack;
			else if (stack->moves < cheapest->moves)
				cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}

t_list	*cheapest_q4(t_list *stack)
{
	t_list	*cheapest;

	cheapest = NULL;
	while (stack)
	{
		if (stack->q4)
		{
			if (!cheapest)
				cheapest = stack;
			else if (stack->moves < cheapest->moves)
				cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
#include <stdio.h>
#include "ft_printf.h"
void	first_rotation(t_list **stack_a, t_list **stack_b, t_val *val)
{
	t_list	*cheapest;

	cheapest = cheapest_q1(stack_a);
	if (!cheapest)
		printf("cheapest is null\n");
	while (*stack_a != cheapest && cheapest->index > val->amedian)
		reverse_rotate_a(stack_a, 1);
	while (*stack_a != cheapest && cheapest->index <= val->amedian)
		rotate_a(stack_a, 1);
	push_b(stack_a, stack_b);
	cheapest = cheapest_q1(stack_a);
	while (*stack_a != cheapest && cheapest->index > val->amedian)
		reverse_rotate_a(stack_a, 1);
	while (*stack_a != cheapest && cheapest->index <= val->amedian)
		rotate_a(stack_a, 1);
	push_b(stack_a, stack_b);
}

void	chechen_sort(t_list **stack_a, t_list **stack_b, t_val *val)
{
	int		len;
	int		quart;
	t_list	*low;

	len = ft_lstsize(*stack_a);
	quart = len / 4;
	quarter(*stack_a, quart);
	a_cost_count(stack_a, val);
	first_rotation(stack_a, stack_b, val);
	len -= 2;
	while (len-- > 3)
	{
		set_min_max(stack_b, val);
		a_cost_count(stack_a, val);
		b_cost_count(stack_b, val);
		assign_target(stack_a, stack_b, val);
		rotate_stacks(stack_a, stack_b, val);
		push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pre_compute(stack_a, stack_b, val);
		top_up(stack_a, stack_b, val);
		push_a(stack_a, stack_b);
	}
	a_cost_count(stack_a, val);
	low = lowest(*stack_a);
	if (*stack_a != low)
		finish_rotate_a(stack_a, low, val);
}

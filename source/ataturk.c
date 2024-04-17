/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ataturk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/16 22:36:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

void	set_min_max(t_list **stack_b, t_val *val)
{
	t_list *tmp;
	long	min;
	long	max;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	min = (long)tmp->content;
	max = (long)tmp->content;
	while (tmp)
	{
		if ((long)tmp->content < min)
			min = (long)tmp->content;
		if ((long)tmp->content > max)
			max = (long) tmp->content;
		tmp = tmp->next;
	}
	val->min = min;
	val->max = max;
}

t_list	*target_node(long n, t_list **stack_b, t_val *val)
{
	t_list	*tmp;
	t_list	*target;
	long	max;

	max = INT_MAX;
	tmp = *stack_b;
	if (n > val->max || n < val->min)
		return (highest(*stack_b));
	while (tmp)
	{
		if (n > (long)tmp->content && n < max)
		{
			max = (long)tmp->content;
			target = tmp;
		}
		if ((long)tmp->content > max && n > (long)tmp->content)
		{
			max = (long)tmp->content;
			target = tmp;
		}
		tmp = tmp->next;
	}
	return (target);
}

// counts how much it costs to put a node at the top
void	cost_count(t_list **stack_a, t_list **stack_b, t_val *val)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	val->amedian = size / 2;
	while (tmp)
	{
		if (i > val->amedian)
			tmp->moves = size - i;
		else
			tmp->moves = i;
		tmp->index = i;
		tmp->target = target_node((long)tmp->content, stack_b, val);
		i++;
		tmp = tmp->next;
	}
}

void	b_cost_count(t_list **stack_b, t_val *val)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = 0;
	tmp = *stack_b;
	size = ft_lstsize(*stack_b);
	val->bmedian = size / 2;
	while (tmp)
	{
		if (i > val->bmedian)
			tmp->moves = size - i;
		else
			tmp->moves = i;
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

t_list	*cheapest(t_list **stack_a)
{
	t_list	*cheapest;
	t_list	*tmp;

	tmp = *stack_a;
	cheapest = *stack_a;
	while (tmp)
	{
		if (tmp->moves + tmp->target->moves < cheapest->moves + cheapest->target->moves)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

void	rotate_stacks(t_list **stack_a, t_list **stack_b, t_val *val)
{
	t_list	*cheap;
	int		i;
	int		j;

	cheap = cheapest(stack_a);
	i = cheap->index;
	j = cheap->target->index;
	while ((*stack_a != cheap && *stack_b != cheap->target) && (i > val->amedian && j > val->bmedian))
	{
		reverse_rotate_all(stack_a, stack_b);
		b_lst_indexing(stack_b, val);
		a_lst_indexing(stack_a, val);
	}
	while ((*stack_a != cheap && *stack_b != cheap->target) && (i <= val->amedian && j <= val->bmedian))
	{
		rotate_all(stack_a, stack_b);
		b_lst_indexing(stack_b, val);
		a_lst_indexing(stack_a, val);
	}
	while (*stack_a != cheap && cheap->index > val->amedian)
		reverse_rotate_a(stack_a, 1);
	while (*stack_a != cheap && cheap->index <= val->amedian)
		rotate_a(stack_a, 1);
	while (cheap->target != *stack_b && cheap->target->index > val->bmedian)
		reverse_rotate_b(stack_b, 1);
	while (cheap->target != *stack_b && cheap->target->index <= val->bmedian)
		rotate_b(stack_b, 1);
	push_b(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b, t_val *val)
{
	int		len;
	t_list	*high;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	len = ft_lstsize(*stack_a);
	while (len--)
	{
		set_min_max(stack_b, val);
		cost_count(stack_a, stack_b, val);
		b_cost_count(stack_b, val);
		rotate_stacks(stack_a, stack_b, val);
	}
	high = highest(*stack_b);
	if (*stack_b != high)
		finish_rotate_b(stack_b, high, val);
	// sort_three(stack_a);
	while (*stack_b)
	{
		push_a(stack_a, stack_b);
	}
}


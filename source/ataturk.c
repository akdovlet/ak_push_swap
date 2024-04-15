/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ataturk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/15 15:00:35 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_max(t_list **stack_b, t_val *val)
{
	t_list *tmp;
	long	min;
	long	max;

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

	tmp = *stack_b;
	if (n > val->max || n < val->min)
		return (highest(*stack_b));
	while (tmp->next)
	{
		if (n > (long)tmp->content && n < (long)tmp->next->content)
			return (tmp);
		if (n < (long)tmp->content && n > (long)tmp->next->content)
			return (tmp->next);
		tmp = tmp->next;
	}
	return (NULL);
}

#include <stdio.h>
// counts how much it costs to put a node at the top
void	cost_count(t_list **stack_a, t_list **stack_b, t_val *val)
{
	int		i;
	int		size;
	int		rmoves;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	val->amedian = size / 2;
	if (size % 2)
		rmoves = val->amedian;
	else
		rmoves = val->amedian - 1;
	while (tmp)
	{
		if (i > val->amedian)
			tmp->moves = rmoves--;
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
	int		rmoves;
	t_list	*tmp;

	i = 0;
	tmp = *stack_b;
	size = ft_lstsize(*stack_b);
	val->bmedian = size / 2;
	if (size % 2)
		rmoves = val->bmedian;
	else
		rmoves = val->bmedian - 1;
	while (tmp)
	{
		if (i > val->bmedian)
			tmp->moves = rmoves--;
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
	while (*stack_a != cheap && (i > val->amedian && j > val->bmedian))
	{
		reverse_rotate_all(stack_a, stack_b);
		i--;
		j--;
		if (i < val->amedian || j < val->bmedian)
			break ;
	}
	while (*stack_a != cheap && cheap->index > val->amedian)
		reverse_rotate_a(stack_a, 1);
}

void	sort(t_list **stack_a, t_list **stack_b, t_val *val)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	set_min_max(stack_b, val);
	cost_count(stack_a, stack_b, val);
	b_cost_count(stack_b, val);
	// push_cheapest(stack_a, stack_b);
}

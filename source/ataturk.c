/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ataturk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 21:45:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	set_min_max(t_list **stack, t_val *val)
{
	t_list	*tmp;
	long	min;
	long	max;

	if (!(*stack))
		return ;
	tmp = *stack;
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

t_list	*target_node(long n, t_list **stack, t_val *val)
{
	t_list	*tmp;
	t_list	*target;
	long	min;

	min = INT_MIN;
	tmp = *stack;
	if (n > val->max || n < val->min)
		return (lowest(*stack));
	while (tmp)
	{
		if (n < (long)tmp->content && n > min)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		if ((long)tmp->content < min && n < (long)tmp->content)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		tmp = tmp->next;
	}
	return (target);
}

// counts how much it costs to put a node at the top
void	a_cost_count(t_list **stack_a, t_val *val)
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
		i++;
		tmp = tmp->next;
	}
}

// counts how much it costs to put a node at the top
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

// Finds the cheapest node to move to the top
t_list	*cheapest(t_list **stack)
{
	t_list	*cheapest;
	t_list	*tmp;

	tmp = *stack;
	cheapest = *stack;
	while (tmp)
	{
		if (tmp->moves + tmp->target->moves < \
			cheapest->moves + cheapest->target->moves)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

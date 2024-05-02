/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intel_gathering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:17:35 by akdovlet          #+#    #+#             */
/*   Updated: 2024/05/02 20:38:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_max(t_stack **stack, t_val *val)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	val->min = *stack;
	val->max = *stack;
	while (tmp)
	{
		if (tmp->nbr < val->min->nbr)
			val->min = tmp;
		if (tmp->nbr > val->max->nbr)
			val->max = tmp;
		tmp = tmp->next;
	}
}

t_stack	*lowest(t_stack *lst)
{
	t_stack	*min;

	min = lst;
	while (lst)
	{
		if (lst->nbr < min->nbr)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

t_stack	*cheapest(t_stack **stack)
{
	t_stack	*cheapest;
	t_stack	*tmp;

	tmp = *stack;
	cheapest = *stack;
	while (tmp)
	{
		if (tmp->moves < cheapest->moves)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

void	a_cost_count(t_stack **stack_a, t_val *val)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	val->amedian = val->asize / 2;
	while (tmp)
	{
		if (i > val->amedian)
			tmp->moves = val->asize - i;
		else
			tmp->moves = i;
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

void	b_cost_count(t_stack **stack_b, t_val *val)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_b;
	val->bmedian = val->bsize / 2;
	while (tmp)
	{
		if (i > val->bmedian)
			tmp->moves = (val->bsize - i);
		else
			tmp->moves = i;
		if (((tmp->target->index <= val->amedian) && (i <= val->bmedian)) \
			|| ((i > val->bmedian) && (tmp->target->index > val->amedian)))
			tmp->moves = biggest(tmp->target->moves, tmp->moves);
		else
			tmp->moves += tmp->target->moves;
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

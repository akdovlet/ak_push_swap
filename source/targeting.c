/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:46:09 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 15:09:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_list	*target_q1(long n, t_list **stack, t_val *val)
{
	t_list	*tmp;
	t_list	*target;
	long	min;

	min = INT_MIN;
	tmp = *stack;
	target = NULL;
	// if (n > val->max || n < val->min)
	// 	return (lowest(*stack));
	while (tmp)
	{
		if ((n < (long)tmp->content && n > min) && tmp->q1)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		if (((long)tmp->content < min && n < (long)tmp->content) && tmp->q1)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
		return (lowest(*stack));
	return (target);
}

t_list	*target_q2(long n, t_list **stack, t_val *val)
{
	t_list	*tmp;
	t_list	*target;
	long	min;

	min = INT_MIN;
	tmp = *stack;
	target = NULL;
	// if (n > val->max || n < val->min)
	// 	return (lowest(*stack));
	while (tmp)
	{
		if ((n < (long)tmp->content && n > min) && tmp->q2)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		if (((long)tmp->content < min && n < (long)tmp->content) && tmp->q2)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
		return (lowest(*stack));
	return (target);
}

t_list	*target_q3(long n, t_list **stack, t_val *val)
{
	t_list	*tmp;
	t_list	*target;
	long	min;

	min = INT_MIN;
	tmp = *stack;
	target = NULL;
	// if (n > val->max || n < val->min)
	// 	return (lowest(*stack));
	while (tmp)
	{
		if ((n < (long)tmp->content && n > min) && tmp->q3)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		if (((long)tmp->content < min && n < (long)tmp->content) && tmp->q3)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
		return (lowest(*stack));
	return (target);
}

t_list	*target_q4(long n, t_list **stack, t_val *val)
{
	t_list	*tmp;
	t_list	*target;
	long	min;

	min = INT_MIN;
	tmp = *stack;
	target = NULL;
	// if (n > val->max || n < val->min)
	// 	return (lowest(*stack));
	while (tmp)
	{
		if ((n < (long)tmp->content && n > min) && tmp->q4)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		if (((long)tmp->content < min && n < (long)tmp->content) && tmp->q4)
		{
			min = (long)tmp->content;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
		return (lowest(*stack));
	return (target);
}

void	assign_qtarget(t_list **hitter, t_list **target, t_val *val)
{
	t_list	*tmp;

	tmp = *hitter;
	while (tmp)
	{
		if (tmp->q1)
			tmp->target = target_q1((long)tmp->content, target, val);
		else if (tmp->q2)
			tmp->target = target_q2((long)tmp->content, target, val);
		else if (tmp->q3)
			tmp->target = target_q3((long)tmp->content, target, val);
		else
			tmp->target = target_q4((long)tmp->content, target, val);
		tmp = tmp->next;
	}
}



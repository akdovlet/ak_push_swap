/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jade.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:41:08 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 22:20:39 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

void	finish_rotate_a(t_list **stack_a, t_list *low, t_val *val)
{
	while (low != *stack_a)
	{
		if (low->index > val->amedian)
			reverse_rotate_a(stack_a, 1);
		else
			rotate_a(stack_a, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jade.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:41:08 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/30 17:02:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack	*target_node(int n, t_stack **stack, t_val *val)
{
	t_stack	*tmp;
	t_stack	*target;
	int		min;

	min = INT_MIN;
	tmp = *stack;
	if (n > val->max->nbr || n < val->min->nbr)
		return (val->min);
	while (tmp)
	{
		if (n < tmp->nbr && n > min)
		{
			min = tmp->nbr;
			target = tmp;
		}
		if (tmp->nbr < min && n < tmp->nbr)
		{
			min = tmp->nbr;
			target = tmp;
		}
		tmp = tmp->next;
	}
	return (target);
}

void	finish_rotate_a(t_stack **stack_a, t_stack *low, t_val *val)
{
	while (low != *stack_a)
	{
		if (low->index > val->amedian)
			reverse_rotate_a(stack_a, 1);
		else
			rotate_a(stack_a, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:33:10 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 21:46:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_list **stack_a, t_list **stack_b, t_val *val, int size)
{
	if (is_sorted(*stack_a))
		return ;
	if (size <= 3)
	{
		if (size == 2)
			sort_two(stack_a);
		else if (size == 3)
			sort_three(stack_a);
	}
	else
		chechen_sort(stack_a, stack_b, val);
}

void	sort_two(t_list **stack_a)
{
	if ((long)(*stack_a)->content > (long)(*stack_a)->next->content)
		swap_a(stack_a, 1);
}

void	sort_three(t_list **stack_a)
{
	t_list	*max;

	max = highest(*stack_a);
	if (*stack_a == max)
		rotate_a(stack_a, 1);
	else if ((*stack_a)->next == max)
		reverse_rotate_a(stack_a, 1);
	if ((long)(*stack_a)->content > (long)(*stack_a)->next->content)
		swap_a(stack_a, 1);
}

int	is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if ((long)stack_a->content > (long)stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jade.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:41:08 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/16 21:10:01 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_lst_indexing(t_list **stack_b, t_val *val)
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

void	a_lst_indexing(t_list **stack_a, t_val *val)
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
		i++;
		tmp = tmp->next;
	}
}

void	finish_rotate_b(t_list **stack_b, t_list *high, t_val *val)
{
	while (high != *stack_b)
	{
		if (high->index > val->bmedian)
			reverse_rotate_b(stack_b, 1);
		else
			rotate_b(stack_b, 1);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ataturk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/12 20:46:32 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pre_check(t_list **stack_b, t_val *val)
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

long	ref_number(long n, t_list **stack_b, t_val *val)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (n > val->max || n < val->min)
		return (val->max);
	while (tmp->next)
	{
		if (n > (long)tmp->content && n < (long)tmp->next->content)
			return ((long)tmp->content);
		if (n < (long)tmp->content && n > (long)tmp->next->content)
			return ((long)tmp->next->content);
		tmp = tmp->next;
	}
	return (0);
}

#include <stdio.h>
// counts how much it costs to put a node at the top
void	top_check(t_list **stack_a, t_list **stack_b, t_val *val)
{
	t_list	*tmp;
	int		moves;
	int		median;
	int		rrmoves;
	int		size;

	moves = 0;
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	printf("size is: %d\n", size);
	if (size % 2)
		median = size / 2;
	else
		median = size / 2 - 1;
	rrmoves = median;
	while (tmp)
	{
		tmp->ref = ref_number((long)tmp->content, stack_b, val);
		if (moves > median)
		{
			tmp->rr = rrmoves;
			rrmoves--;
		}
		else
			tmp->r = moves;
		moves++;
		tmp = tmp->next;
	}
}

void	b_top_check(t_list **stack_b)
{
	int	moves;
	int	rrmoves;
	int	median;
	int size;
	t_list	*tmp;

	moves = 0;
	size = ft_lstsize(*stack_b);
	tmp = *stack_b;
	if (size % 2)
		median = size / 2;
	else
		median = size / 2 - 1;
	rrmoves = median;
	while (tmp)
	{
		if (moves > median)
		{
			tmp->rr = rrmoves;
			rrmoves--;
		}
		else
			tmp->r = moves;
		moves ++;
		tmp = tmp->next;
	}
}
void	cheap_counter(t_list *a, t_list *b)
{
	t_list *head;

	while (a)
	{
		head = b;
		while (head)
		{
			if (a->ref == (long)head->content)
			{
				if (a->r && head->r)
				{
					a->ra = smallest(a->r, head->r);
					a->r = a->r - a->ra;
					head->r = head->r - a->ra;
				}
				else if (a->rr && head->rr)
				{
					a->rra = smallest(a->rr, head->rr);
					a->rr -= a->rra;
					head->rr -= a->rra;
				}
				a->total = a->r + a->rr + head->r + head->rr;
			}
			head = head->next;
		}
		a = a->next;
	}
}

t_list	*cheapest_finder(t_list *a)
{
	int	cheapest;
	t_list *cheap;

	cheapest = a->total;
	cheap = a;
	while (a)
	{
		if (cheapest > a->total)
		{
			cheapest = a->total;
			cheap = a;
		}
		a = a->next;
	}
	return (cheap);
}

t_list *ref_finder(long ref, t_list	*b)
{
	while (b)
	{
		if (ref == (long)b->content)
			return (b);
		b = b->next;
	}
	return (b);
}

void	push_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;
	t_list	*ref;

	cheapest = cheapest_finder(*stack_a);
	ref = ref_finder((long)cheapest->content, *stack_b);
	while (cheapest->rra)
	{
		reverse_rotate_all(stack_a, stack_b);
		cheapest->rra = cheapest->rra - 1;
	}
	while (cheapest->ra)
	{
		rotate_all(stack_a, stack_b);
		cheapest->ra = cheapest->ra - 1;
	}
	while (cheapest->r || cheapest->rr)
	{
		if (cheapest->r)
		{
			rotate_a(stack_a, 1);
			cheapest->r = cheapest->r - 1;
		}
		if (cheapest->rr)
		{
			reverse_rotate_a(stack_a, 1);
			cheapest->rr = cheapest->rr - 1;
		}
	}
	while (ref->r || ref->rr)
	{
		if (ref->r)
		{
			rotate_b(stack_b, 1);
			ref->r = ref->r - 1;
		}
		if (ref->rr)
		{
			reverse_rotate_b(stack_b, 1);
			ref->rr = ref-> rr - 1;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b, t_val *val)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	pre_check(stack_b, val);
	top_check(stack_a, stack_b, val);
	b_top_check(stack_b);
	cheap_counter(*stack_a, *stack_b);
	// push_cheapest(stack_a, stack_b);
}

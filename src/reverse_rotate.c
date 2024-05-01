/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:47:00 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/30 17:05:35 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	reverse_rotate_a(t_stack **a, int bin)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	last = ft_stacklast(*a);
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	if (bin)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **b, int bin)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	last = ft_stacklast(*b);
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
	if (bin)
		ft_printf("rrb\n");
}

void	reverse_rotate_all(t_stack **a, t_stack **b, int bin)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	if (bin)
		ft_printf("rrr\n");
}

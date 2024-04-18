/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:47:00 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 21:45:28 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	reverse_rotate_a(t_list **a, int bin)
{
	t_list	*last;
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	if (bin)
		ft_printf("rra\n");
}

// Shift down all elements of stack b by 1. 
// The last element becomes the first one.
void	reverse_rotate_b(t_list **b, int bin)
{
	t_list	*last;
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
	if (bin)
		ft_printf("rrb\n");
}

void	reverse_rotate_all(t_list **a, t_list **b)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
}

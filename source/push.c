/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:19:17 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 21:48:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// push a - take the first element at the top of b and put 
// it at the top of a. Do nothing if b is empty.
void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!(*b))
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_printf("pa\n");
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_printf("pb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:19:17 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/22 19:25:03 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	push_a(t_list **a, t_list **b, int bin)
{
	t_list	*tmp;

	if (!(*b))
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	if (bin)
		ft_printf("pa\n");
}

void	push_b(t_list **a, t_list **b, int bin)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	if (bin)
		ft_printf("pb\n");
}

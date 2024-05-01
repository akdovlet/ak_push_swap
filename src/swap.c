/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:46:24 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/29 16:18:06 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	swap_a(t_stack **lst, int bin)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = (*lst)->next->next;
	*lst = (*lst)->next;
	(*lst)->next = tmp;
	(*lst)->next->next = tmp2;
	if (bin)
		ft_printf("sa\n");
}

void	swap_b(t_stack **lst, int bin)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = (*lst)->next->next;
	*lst = (*lst)->next;
	(*lst)->next = tmp;
	(*lst)->next->next = tmp2;
	if (bin)
		ft_printf("sb\n");
}

void	swap_a_b(t_stack **a, t_stack **b, int bin)
{
	swap_a(a, 0);
	swap_b(b, 0);
	if (bin)
		ft_printf("ss\n");
}

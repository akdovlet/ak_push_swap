/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:46:24 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/19 00:24:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	swap_a(t_list **lst, int bin)
{
	t_list	*tmp;
	t_list	*tmp2;

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

void	swap_b(t_list **lst, int bin)
{
	t_list	*tmp;
	t_list	*tmp2;

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

void	swap_a_b(t_list **a, t_list **b, int bin)
{
	swap_a(a, 0);
	swap_b(b, 0);
	if (bin)
		ft_printf("ss\n");
}

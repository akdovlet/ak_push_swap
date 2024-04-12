/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:46:24 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/09 17:35:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
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

void	swap_a_b(t_list **a, t_list **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	ft_printf("ss\n");
}

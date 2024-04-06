/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:46:24 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/04 15:41:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	swap_a(t_list **lst, int bin)
{
	long	tmp;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = (long)(*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = (void *)tmp;
	if (bin)
		ft_printf("sa\n");
}

void	swap_b(t_list **lst, int bin)
{
	long	tmp;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = (long)(*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = (void *)tmp;
	if (bin)
		ft_printf("sb\n");
}

void	swap_a_b(t_list **a, t_list **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	ft_printf("ss\n");
}

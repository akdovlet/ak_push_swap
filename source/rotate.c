/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:28:30 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/12 19:20:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	rotate_a(t_list **a, int bin)
{
	t_list	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->next;
	ft_lstadd_back(a, *a);
	(*a)->next = NULL;
	*a = tmp;
	if (bin)
		ft_printf("ra\n");
}

void	rotate_b(t_list **b, int bin)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	ft_lstadd_back(b, *b);
	(*b)->next = NULL;
	*b = tmp;
	if (bin)
		ft_printf("rb\n");
}

void	rotate_all(t_list **a, t_list **b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	ft_printf("rr\n");
}

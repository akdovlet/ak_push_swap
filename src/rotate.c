/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:28:30 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/30 17:06:51 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	rotate_a(t_stack **a, int bin)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->next;
	ft_stackadd_back(a, *a);
	(*a)->next = NULL;
	*a = tmp;
	if (bin)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **b, int bin)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	ft_stackadd_back(b, *b);
	(*b)->next = NULL;
	*b = tmp;
	if (bin)
		ft_printf("rb\n");
}

void	rotate_all(t_stack **a, t_stack **b, int bin)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	if (bin)
		ft_printf("rr\n");
}

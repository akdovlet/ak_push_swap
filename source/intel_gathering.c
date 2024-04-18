/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intel_gathering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:17:35 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 21:48:03 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*highest(t_list *lst)
{
	t_list	*tmp;
	t_list	*max;

	tmp = lst;
	max = lst;
	while (tmp)
	{
		if ((long)tmp->content > (long)max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_list	*lowest(t_list *lst)
{
	t_list	*min;

	min = lst;
	while (lst)
	{
		if ((long)lst->content < (long)min->content)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

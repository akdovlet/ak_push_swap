/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:48:11 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/06 18:08:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

long	*parse_and_check(t_list **lst, char **av, int ac, t_val *val)
{
	long	*tab;

	if (!stack_creation(lst, av, ac, val) || val->size == -1)
	{
		ps_lstclear(lst, free);
		ft_printf("Error\n");
		return (NULL);
	}
	tab = copy_stack(*lst, val->size);
	if (!tab)
	{
		ps_lstclear(lst, free);
		ft_printf("Error\n");
		return (NULL);
	}
	ak_quicksort(tab, 0, val->size - 1);
	if (!duplicate_check(tab, val->size))
	{
		ps_lstclear(lst, free);
		free(tab);
		ft_printf("Error\n");
		return (NULL);
	}
	indexing(*lst, tab, val->size);
	return (tab);
}

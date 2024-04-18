/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:48:11 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 21:21:04 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*clear_free(t_list **lst, long *tab, int bin)
{
	ps_lstclear(lst, free);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (bin)
		free(tab);
	return (NULL);
}

long	*parse_and_check(t_list **lst, char **av, int ac, t_val *val)
{
	long	*tab;

	tab = NULL;
	if (!stack_creation(lst, av, ac, val) || val->size == -1)
		return (clear_free(lst, tab, 0));
	tab = copy_stack(*lst, val->size);
	if (!tab)
		return (clear_free(lst, tab, 0));
	ak_quicksort(tab, 0, val->size - 1);
	if (!duplicate_check(tab, val->size))
		return (clear_free(lst, tab, 1));
	indexing(*lst, tab, val->size);
	val->median = median(tab, val->size);
	return (tab);
}

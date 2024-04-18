/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:48:11 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 22:22:20 by akdovlet         ###   ########.fr       */
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

int	duplicate_check(long *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		if (arr[i] == arr[i + 1])
			return (0);
	return (1);
}

int	char_check(char c)
{
	if (ft_isdigit(c) || c == '-' || c == 32)
		return (1);
	return (0);
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
	val->median = median(tab, val->size);
	return (tab);
}

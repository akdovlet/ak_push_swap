/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:48:11 by akdovlet          #+#    #+#             */
/*   Updated: 2024/05/01 19:23:20 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*clear_free(t_stack **lst, int *array, bool bin)
{
	ft_stackclear(lst);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (bin)
		free(array);
	return (NULL);
}

bool	duplicate_check(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		if (arr[i] == arr[i + 1])
			return (false);
	return (true);
}

bool	char_check(char c)
{
	if (c == '-' || c == '+' || ft_isspace(c) || ft_isdigit(c))
		return (true);
	return (false);
}

bool	start_extraction(char c)
{
	if (ft_isdigit(c) || c == '-' || c == '+')
		return (true);
	return (false);
}

bool	parse_and_check(t_stack **lst, char **av, int ac, t_val *val)
{
	int	*array;

	array = NULL;
	if (!stack_creation(lst, av, ac, val))
		return (clear_free(lst, array, 0));
	array = copy_stack(*lst, val->asize);
	if (!array)
		return (clear_free(lst, array, 0));
	ak_quicksort(array, 0, val->asize - 1);
	if (!duplicate_check(array, val->asize))
		return (clear_free(lst, array, 1));
	val->median = median(array, val->asize - 1);
	free(array);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:42:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/05/01 19:27:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	smallest(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	biggest(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	median(int *tab, int size)
{
	if (size % 2)
		return (tab[(size) / 2]);
	return ((tab[(size - 1) / 2] + tab[(size) / 2]) / 2);
}

// if (nb > (INT_MAX - digit) / 10)
int	ak_atoi(const char *nptr, int *i)
{
	long	nb;
	long	flip;

	nb = 0;
	flip = 1;
	while (nptr[*i] && ft_isspace(nptr[*i]))
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			flip *= -1;
		(*i)++;
	}
	while (nptr[*i] && ft_isdigit(nptr[*i]))
	{
		nb = nb * 10 + (nptr[*i] - 48);
		if (nb * flip > INT_MAX || nb * flip < INT_MIN)
			return (*i = -1, 0);
		(*i)++;
	}
	if (nptr[*i] && !ft_isspace(nptr[*i]))
		*i = -1;
	return (nb * flip);
}

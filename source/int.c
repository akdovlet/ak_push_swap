/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:42:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 17:22:38 by akdovlet         ###   ########.fr       */
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

long	median(long *tab, int size)
{
	if (size % 2)
		return (tab[(size - 1) / 2]);
	return ((tab[(size - 2) / 2] + tab[(size - 1) / 2]) / 2);
}

long	ak_atol(const char *nptr, t_val *val)
{
	int		i;
	long	flip;
	long	nb;

	i = 0;
	nb = 0;
	flip = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flip *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + nptr[i] - 48;
		if (nb > INT_MAX || nb < INT_MIN)
			val->size = -1;
		i++;
	}
	if (!(nptr[i] >= 9 && nptr[i] <= 13) && nptr[i] != 32 && nptr[i] != '\0')
		val->size = -1;
	return (nb * flip);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:49:55 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/06 13:14:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_swap(long *a, long *b)
{
	long	c;

	c = *a;
	*a = *b;
	*b = c;
}

long	partition(long *arr, int low, int high)
{
	long	pivot;
	int		i;
	long	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	ak_quicksort(long *arr, int low, int high)
{
	long	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		ak_quicksort(arr, low, pivot - 1);
		ak_quicksort(arr, pivot + 1, high);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:10:12 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/29 16:19:17 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_stack(t_stack *lst, int size)
{
	int		i;
	int		*arr;

	if (!size || !lst)
		return (NULL);
	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (lst)
	{
		arr[i] = lst->nbr;
		i++;
		lst = lst->next;
	}
	return (arr);
}

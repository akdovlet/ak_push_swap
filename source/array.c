/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:10:12 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 21:47:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*copy_stack(t_list *lst, int size)
{
	int		i;
	long	*arr;

	if (!size || !lst)
		return (NULL);
	i = 0;
	arr = malloc(sizeof(long) * size);
	if (!arr)
		return (NULL);
	while (lst)
	{
		arr[i] = (long) lst->content;
		i++;
		lst = lst->next;
	}
	return (arr);
}

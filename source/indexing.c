/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:14:28 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 21:17:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list *lst, long *tab, int size)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (i < size)
		{
			if ((long)lst->content == tab[i])
			{
				lst->end = i;
				break ;
			}
			i++;
		}
		lst = lst->next;
	}
}

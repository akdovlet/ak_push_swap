/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:14:28 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/17 17:31:20 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

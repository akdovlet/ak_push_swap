/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:41:56 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/12 20:21:17 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->max = 0;
	node->min = 0;
	node->r = 0;
	node->rr = 0;
	node->total = 0;
	node->ra = 0;
	node->rra = 0;
	node->ref = 0;
	node->next = NULL;
	return (node);
}

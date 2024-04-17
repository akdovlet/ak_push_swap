/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:41:56 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/17 19:02:31 by akdovlet         ###   ########.fr       */
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
	node->moves = 0;
	node->ref = 0;
	node->end = 0;
	node->q1 = 0;
	node->q2 = 0;
	node->q3 = 0;
	node->q4 = 0;
	node->index = 0;
	node->target = NULL;
	node->next = NULL;
	return (node);
}

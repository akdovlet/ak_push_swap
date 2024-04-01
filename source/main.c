/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:22:03 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/01 17:22:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_list *lst;
	t_list *head;
	int		i;

	i = 0;
	lst = NULL;
	stack_creation(&lst, av, ac);
	head = lst;
	while (lst)
	{
		printf("content is: %ld\n", (long)lst->content);
		lst = lst->next;
	}
	ps_lstclear(&head, free);
	return (0);
}

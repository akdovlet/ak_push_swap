/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:22:03 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/06 18:09:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("content is: %ld\n", (long)lst->content);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_val	aval;
	long	*tab;
	int		i;

	if (ac == 1)
		return (0);
	i = 0;
	lst = NULL;
	aval.size = 0;
	tab = parse_and_check(&lst, av, ac, &aval);
	if (!tab)
		return (0);
	// while (lst)
	// {
	// 	printf("content is: %ld, index is: %d\n", (long)lst->content, lst->index);
	// 	lst = lst->next;
	// }
	print_array(tab, aval.size);
	ps_lstclear(&lst, free);
	return (0);
}

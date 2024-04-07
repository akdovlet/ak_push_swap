/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:22:03 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/07 19:57:48 by akdovlet         ###   ########.fr       */
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
		printf("value is: %ld\n", (long)lst->content);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_val	aval;
	t_list *stack_b;
	long	*tab;
	int		i;

	if (ac == 1)
		return (0);
	i = 0;
	lst = NULL;
	aval.size = 0;
	stack_b = NULL;
	tab = parse_and_check(&lst, av, ac, &aval);
	print_list(lst);
	printf("\n");
	if (!tab)
		return (0);
	solver(&lst, tab, aval.size);
	print_list(lst);
	ps_lstclear(&lst, free);
	return (0);
}

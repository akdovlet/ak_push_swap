/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:22:03 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/18 17:23:25 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdio.h>

void	print_list(t_list *lst)
{
	
	while (lst)
	{
		printf("value is: %ld; ", (long)lst->content);
		printf("ref number is: %ld; ", (long)lst->target->content);
		printf("moves: %d\n", lst->moves);
		lst = lst->next;
	}
}

void	print_b(t_list *lst)
{
	
	while (lst)
	{
		printf("%ld\n", (long)lst->content);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_val	val;
	long	*tab;

	if (ac == 1)
		return (0);
	val.size = 0;
	stack_a = NULL;
	stack_b = NULL;
	tab = parse_and_check(&stack_a, av, ac, &val);
	if (!tab)
		return (0);
	solver(&stack_a, &stack_b, &val, val.size);
	print_b(stack_a);
	ps_lstclear(&stack_a, free);
	free(tab);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:22:03 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/12 20:23:03 by akdovlet         ###   ########.fr       */
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
		printf("value is: %ld; ", (long)lst->content);
		printf("rotate is: %ld; ", (long)lst->r);
		printf("reverse rotate is: %ld; ", (long)lst->rr);
		printf("ref number is: %ld; ", (long)lst->ref);
		printf("total moves is: %d; ", lst->total);
		printf("rotate all is: %ld; ", (long)lst->ra);
		printf("reverse rotate all is: %ld\n", (long)lst->rra);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_val	aval;
	t_list	*stack_b;
	long	*tab;
	int		i;

	if (ac == 1)
		return (0);
	i = 0;
	lst = NULL;
	aval.size = 0;
	stack_b = NULL;
	tab = parse_and_check(&lst, av, ac, &aval);
	if (!tab)
		return (0);
	sort(&lst, &stack_b, &aval);
	// print_list(lst);
	// printf("========================\n");
	print_list(stack_b);
	printf("min is: %ld, max is: %ld\n", aval.min, aval.max);
	printf("\n");
	// solver(&lst, tab, aval.size);
	// print_list(lst);
	// ps_lstclear(&lst, free);
	return (0);
}


// 7 5 41 23 69 -5
// 9 1

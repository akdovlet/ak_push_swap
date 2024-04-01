/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:55:55 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/01 16:56:49 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	char_check(char c)
{
	if (ft_isdigit(c) || c == '-' || c == 32)
		return (1);
	return (0);
}

void	ps_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		del(*lst);
		*lst = tmp;
	}
}

int	parse_av(t_list **lst, char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] && !char_check(av[i]))
			return (0);
		if (av[i] && (ft_isdigit(av[i]) || av[i] == '-'))
		{
			ft_lstadd_back(lst, ft_lstnew((void *)ft_atol(av + i)));
			if (!(*lst))
				return (0);
			while (av[i] && (ft_isdigit(av[i]) || av[i] == '-'))
				i++;
		}
		else
			i++;
	}
	return (1);
}

void	stack_creation(t_list **lst, char **av, int ac)
{
	int		i;
	int		err;

	i = 1;
	err = 1;
	while (i < ac)
	{
		err = parse_av(lst, av[i]);
		if (!err)
			return (ft_printf("Error\n"), ps_lstclear(lst, free)); 
		i++;
	}
}

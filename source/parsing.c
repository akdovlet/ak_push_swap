/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:55:55 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/19 18:12:44 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	parse_av(t_list **lst, char *av, t_val *val)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] && !char_check(av[i]))
			return (0);
		if (av[i] && (ft_isdigit(av[i]) || av[i] == '-'))
		{
			if (av[i] == '-' && !ft_isdigit(av[i + 1]))
				return (val->size = -1, 0);
			ft_lstadd_back(lst, ft_lstnew((void *)ak_atol(av + i, val)));
			if (val->size == -1)
				return (0);
			val->size = val->size + 1;
			if (!(*lst))
				return (val->size = -1, 0);
			while (av[i] && (ft_isdigit(av[i]) || av[i] == '-'))
				i++;
		}
		else
			i++;
	}
	return (1);
}

int	stack_creation(t_list **lst, char **av, int ac, t_val *val)
{
	int		i;
	int		err;
	int		control;

	i = 1;
	err = 1;
	control = val->size;
	while (i < ac)
	{
		err = parse_av(lst, av[i], val);
		if (!err || control == val->size)
			return (ps_lstclear(lst, free), 0);
		control = val->size;
		i++;
	}
	return (1);
}

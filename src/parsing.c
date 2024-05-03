/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:55:55 by akdovlet          #+#    #+#             */
/*   Updated: 2024/05/02 22:01:55 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	parse_av(t_stack **lst, char *av, t_val *val)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (av[i])
	{
		if (!char_check(av[i]))
			return (false);
		if (start_extraction(av[i]))
		{
			if ((av[i] == '+' || av[i] == '-') && !ft_isdigit(av[i + 1]))
				return (false);
			new = ft_stacknew(ak_atoi(av, &i));
			if (!new || i == -1)
				return (free(new), false);
			ft_stackadd_back(lst, new);
			val->asize = val->asize + 1;
		}
		else
			i++;
	}
	return (true);
}

bool	stack_creation(t_stack **lst, char **av, int ac, t_val *val)
{
	int		i;
	int		err;
	int		control;

	i = 1;
	err = true;
	val->asize = 0;
	val->bsize = 0;
	control = val->asize;
	while (i < ac)
	{
		err = parse_av(lst, av[i], val);
		if (!err || control == val->asize)
			return (ft_stackclear(lst), false);
		control = val->asize;
		i++;
	}
	return (true);
}

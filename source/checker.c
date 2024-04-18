/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:11:34 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/19 01:52:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	keep_reading(void)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return ;
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_val	val;
	long	*tab;

	if (ac == 1)
		return (keep_reading(), 0);
	val.size = 0;
	stack_a = NULL;
	stack_b = NULL;
	tab = parse_and_check(&stack_a, av, ac, &val);
	if (!tab)
		return (0);
	checker_driver(&stack_a, &stack_b);
	ps_lstclear(&stack_a, free);
	ps_lstclear(&stack_b, free);
	free(tab);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:10:03 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/19 01:52:17 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (0);
}

int	execute_orders(t_list **stack_a, t_list **stack_b, char *order)
{
	if (!ft_strcmp(order, "sa\n"))
		swap_a(stack_a, 0);
	else if (!ft_strcmp(order, "sb\n"))
		swap_b(stack_b, 0);
	else if (!ft_strcmp(order, "ss\n"))
		swap_a_b(stack_a, stack_b, 0);
	else if (!ft_strcmp(order, "pa\n"))
		push_a(stack_a, stack_b, 0);
	else if (!ft_strcmp(order, "pb\n"))
		push_b(stack_a, stack_b, 0);
	else if (!ft_strcmp(order, "ra\n"))
		rotate_a(stack_a, 0);
	else if (!ft_strcmp(order, "rb\n"))
		rotate_b(stack_b, 0);
	else if (!ft_strcmp(order, "rr\n"))
		rotate_all(stack_a, stack_b, 0);
	else if (!ft_strcmp(order, "rra\n"))
		reverse_rotate_a(stack_a, 0);
	else if (!ft_strcmp(order, "rrb\n"))
		reverse_rotate_b(stack_b, 0);
	else if (!ft_strcmp(order, "rrr\n"))
		reverse_rotate_all(stack_a, stack_b, 0);
	else
		return (error());
	return (1);
}

void	checker_driver(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!execute_orders(stack_a, stack_b, line))
			return ;
		free(line);
	}
	if (is_sorted(*stack_a) && !*stack_b)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	free(line);
}

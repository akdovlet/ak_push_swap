/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:22:03 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/30 17:02:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Use as such: ARG=$(seq 500 | shuf | tr '\n' ' ')
// Or ARG=$(shuf -i 0-10000 -n 500 | tr '\n' ' ')
// Then: ./push_swap $ARG | ./checker $ARG
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_val	val;

	if (ac == 1)
		return (1);
	val.asize = 0;
	val.bsize = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_and_check(&stack_a, av, ac, &val))
		return (1);
	solver(&stack_a, &stack_b, &val, val.asize);
	ft_stackclear(&stack_a);
	return (0);
}

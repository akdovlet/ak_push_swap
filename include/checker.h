/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:15:01 by akdovlet          #+#    #+#             */
/*   Updated: 2024/04/19 01:52:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	checker_driver(t_list **stack_a, t_list **stack_b);
int		execute_orders(t_list **stack_a, t_list **stack_b, char *order);
int		error(void);
int		ft_strcmp(char *s1, char *s2);

#endif

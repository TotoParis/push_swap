/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:50:51 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:24:07 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parse_args(argv);
	if (!stack_a)
		return (ft_putstr_fd(NO_STACK, 2), 0);
	if (!check_double(stack_a))
		return (ft_stkclear(&stack_a), ft_putstr_fd(NO_DOUBLE, 2), 0);
	if (already_sorted(stack_a))
		return (ft_stkclear(&stack_a), 0);
	push_swap(&stack_a, &stack_b);
	ft_stkclear(&stack_a);
	return (0);
}

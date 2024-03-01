/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:50:51 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/01 17:56:59 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;


	if (argc < 2)
		return (ft_printf(NO_ARGS));
	stack = parse_args(argv);
	if (!stack)
		return (ft_printf(NO_STACK));
	if (!check_double(stack))
		return (ft_printf(NO_DOUBLE));
	if (already_sorted(stack))
		return (0);
		
	return (0);
}


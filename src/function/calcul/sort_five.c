/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:19:01 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/02 17:21:28 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		median;
	int		min_pos;
	int		min;

	while (ft_stklast((*stack_a))->pos != 3)
	{
		median = median(stack_a);
		min_pos = min_pos(stack_a);
		min = min(stack_a);
		while ((*stack_a)->nb != min)
		{
			if (min_pos > median)
				lst_reverse_rotate_a(stack_a);
			else
				lst_rotate_a(stack_a);
		}
		lst_push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		lst_push_a(stack_b, stack_a);
}
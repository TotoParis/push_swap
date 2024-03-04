/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:19:01 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:27:29 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		med;
	int		min_id;
	int		min;

	while (ft_stklast((*stack_a))->id != 3)
	{
		med = median(stack_a);
		min_id = get_min_id(stack_a);
		min = get_min(stack_a);
		while ((*stack_a)->nb != min)
		{
			if (min_id > med)
				reverse_a(stack_a);
			else
				rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		push_a(stack_b, stack_a);
}

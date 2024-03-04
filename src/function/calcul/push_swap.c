/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:33:47 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:27:02 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (ft_stklast(tmp)->id == 2)
		swap_a(stack_a);
	else if (ft_stklast(tmp)->id == 3)
		sort_three(stack_a);
	else if (ft_stklast(tmp)->id < 6)
		sort_five(stack_a, stack_b);
	else
		sort(stack_a, stack_b);
}

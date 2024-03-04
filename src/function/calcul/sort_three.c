/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:29:49 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:27:27 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->nb;
	second = (*stack_a)->next->nb;
	third = (*stack_a)->next->next->nb;
	if (first > second && first > third && second > third)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (first > second && first > third && second < third)
		rotate_a(stack_a);
	else if (first < second && first > third && second > third)
		reverse_a(stack_a);
	else if (first > second && first < third && second < third)
		swap_a(stack_a);
	else if (first < second && first < third && second > third)
	{
		reverse_a(stack_a);
		swap_a(stack_a);
	}
}

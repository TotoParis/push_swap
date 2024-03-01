/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:51:53 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/01 17:53:44 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	update_id(stack);
}

void	swap_a(t_stack **a)
{
	swap(a);
}

void	swap_b(t_stack **b)
{
	swap(b);
}	

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
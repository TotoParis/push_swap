/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:00:01 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/01 18:00:18 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (!*stack1)
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = *stack2;
	*stack2 = tmp;
}

void	push_a(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	push_b(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	push_both(t_stack **a, t_stack **b)
{
	push(a, b);
	push(b, a);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:04 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/01 18:17:12 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = ft_stklast(*stack);
	*stack = (*stack)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	reverse_a(t_stack **a)
{
	reverse(a);
}

void	reverse_b(t_stack **b)
{
	reverse(b);
}

void	reverse_both(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
}

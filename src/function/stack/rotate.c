/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:24:19 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:25:29 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	ft_stkadd_back(stack, tmp);
	*stack = (*stack)->next;
	tmp->next = NULL;
	update_id(stack);
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

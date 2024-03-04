/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:15:04 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:24:29 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = ft_stklast(*stack);
	ft_stkadd_front(stack, tmp);
	tmp2 = *stack;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	update_id(stack);
}

void	reverse_a(t_stack **a)
{
	reverse(a);
	ft_printf("rra\n");
}

void	reverse_b(t_stack **b)
{
	reverse(b);
	ft_printf("rrb\n");
}

void	reverse_both(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	ft_printf("rrr\n");
}

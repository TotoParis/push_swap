/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:02:18 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:24:53 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

t_stack	*ft_stklast(t_stack *stack)
{
	t_stack	*t;

	t = stack;
	while (t)
	{
		if (!t->next)
			return (t);
		t = t->next;
	}
	return (t);
}

void	ft_stkadd_front(t_stack **stack, t_stack *new)
{
	if (!stack && !new)
		return ;
	new->next = *stack;
	*stack = new;
}

void	ft_stkadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*t;

	if (!new)
		return ;
	if (!*stack)
		return (ft_stkadd_front(stack, new));
	t = ft_stklast(*stack);
	t->next = new;
}

void	ft_stkclear(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

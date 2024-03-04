/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:51:53 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:25:07 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	swap(t_stack **stack)
{
	int		nbr1;
	int		nbr2;
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	nbr1 = tmp->nb;
	nbr2 = tmp->next->nb;
	tmp->nb = nbr2;
	tmp->next->nb = nbr1;
	update_id(stack);
}

void	swap_a(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}	

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

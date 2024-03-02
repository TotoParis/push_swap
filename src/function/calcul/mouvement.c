/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:39:26 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/02 17:42:52 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	rra_rrb(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	pos_a = reverse_pos(a, pos_a);
	pos_b = reverse_pos(b, pos_b);
	while (pos_a > 1 && pos_b > 1)
	{
		reverse_both(a, b);
		pos_a--;
		pos_b--;
	}
	if (pos_a > 1)
	{
		while (pos_a > 1)
		{
			reverse_a(a);
			pos_a--;
		}
	}
	else
	{
		while (pos_b > 1)
		{
			reverse_b(b);
			pos_b--;
		}
	}
}

void	rra_rb(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	pos_a = reverse_pos(a, pos_a);
	while (pos_a > 1 && pos_b > 1)
	{
		reverse_a(a);
		rotate_b(b);
		pos_a--;
		pos_b--;
	}
	if (pos_a > 1)
	{
		while (pos_a > 1)
		{
			reverse_a(a);
			pos_a--;
		}
	}
	else
	{
		while (pos_b > 1)
		{
			rotate_b(b);
			pos_b--;
		}
	}
}

void	ra_rrb(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	pos_b = reverse_pos(b, pos_b);
	while (pos_a > 1 && pos_b > 1)
	{
		rotate_a(a);
		reverse_b(b);
		pos_a--;
		pos_b--;
	}
	if (pos_a > 1)
	{
		while (pos_a > 1)
		{
			rotate_a(a);
			pos_a--;
		}
	}
	else
	{
		while (pos_b > 1)
		{
			reverse_b(b);
			pos_b--;
		}
	}
}

void	ra_rb(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while (pos_a > 1 && pos_b > 1)
	{
		rotate_both(a, b);
		pos_a--;
		pos_b--;
	}
	if (pos_a > 1)
	{
		while (pos_a > 1)
		{
			rotate_a(a);
			pos_a--;
		}
	}
	else
	{
		while (pos_b > 1)
		{
			rotate_b(b);
			pos_b--;
		}
	}
}

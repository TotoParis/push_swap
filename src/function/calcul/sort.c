/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:12:37 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/02 17:50:05 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	int	nbr_a;
	int	nbr_b;

	push_b(a, b);
	push_b(a, b);
	while (*a)
	{
		if (get_min(b) > (*a)->nb || get_max(b) < (*a)->nb)
		{
			move_to_top_b(b, get_max_id(b));
			push_b(a, b);
		}
		else
		{
			cost(a, b, &nbr_a, &nbr_b);
			double_rotation(a, b, get_id(a, nbr_a),
				get_id(b, nbr_b));
			push_b(a, b);
		}
	}
	while (*b)
	{
		move_to_top_b(b, max_pos(b));
		push_a(b, a);
	}
}

void	double_rotation(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	t_cost	cost;
	int		min_cost;

	cost.ra_rb = compare_cost(pos_a, pos_b);
	cost.rra_rrb = compare_cost(reverse_pos(a, pos_a),
			reverse_pos(b, pos_b));
	cost.rra_rb = reverse_pos(a, pos_a) + pos_b ;
	cost.ra_rrb = pos_a + reverse_pos(b, pos_b);
	min_cost = cheaper_move(cost);
	if (min_cost == cost.rra_rrb)
		rra_rrb(a, b, pos_a, pos_b);
	else if (min_cost == cost.rra_rb)
		rra_rb(a, b, pos_a, pos_b);
	else if (min_cost == cost.ra_rrb)
		ra_rrb(a, b, pos_a, pos_b);
	else
		ra_rb(a, b, pos_a, pos_b);
}

void	move_to_top_b(t_stack **b, int pos)
{
	if (pos > median(b))
	{
		pos = reverse_pos(b, pos);
		while (pos > 1)
		{
			reverse_rotate_b(b);
			pos--;
		}
	}
	else
	{
		while (pos > 1)
		{
			rotate_b(b);
			pos--;
		}
	}
}

int	reverse_pos(t_stack **stack, int pos)
{
	int		size;
	int		i;

	size = ft_stklast(*stack)->id;
	i = 1;
	while (size >= pos)
	{
		i++;
		pos++;
	}
	return (i);
}
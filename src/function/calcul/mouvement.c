/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:39:26 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/03 13:56:49 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	rra_rrb(t_stack **a, t_stack **b, int id_a, int id_b)
{
	id_a = reverse_id(a, id_a);
	id_b = reverse_id(b, id_b);
	while (id_a > 1 && id_b > 1)
	{
		reverse_both(a, b);
		id_a--;
		id_b--;
	}
	if (id_a > 1)
	{
		while (id_a > 1)
		{
			reverse_a(a);
			id_a--;
		}
	}
	else
	{
		while (id_b > 1)
		{
			reverse_b(b);
			id_b--;
		}
	}
}

void	rra_rb(t_stack **a, t_stack **b, int id_a, int id_b)
{
	id_a = reverse_id(a, id_a);
	while (id_a > 1 && id_b > 1)
	{
		reverse_a(a);
		rotate_b(b);
		id_a--;
		id_b--;
	}
	if (id_a > 1)
	{
		while (id_a > 1)
		{
			reverse_a(a);
			id_a--;
		}
	}
	else
	{
		while (id_b > 1)
		{
			rotate_b(b);
			id_b--;
		}
	}
}

void	ra_rrb(t_stack **a, t_stack **b, int id_a, int id_b)
{
	id_b = reverse_id(b, id_b);
	while (id_a > 1 && id_b > 1)
	{
		rotate_a(a);
		reverse_b(b);
		id_a--;
		id_b--;
	}
	if (id_a > 1)
	{
		while (id_a > 1)
		{
			rotate_a(a);
			id_a--;
		}
	}
	else
	{
		while (id_b > 1)
		{
			reverse_b(b);
			id_b--;
		}
	}
}

void	ra_rb(t_stack **a, t_stack **b, int id_a, int id_b)
{
	while (id_a > 1 && id_b > 1)
	{
		rotate_both(a, b);
		id_a--;
		id_b--;
	}
	if (id_a > 1)
	{
		while (id_a > 1)
		{
			rotate_a(a);
			id_a--;
		}
	}
	else
	{
		while (id_b > 1)
		{
			rotate_b(b);
			id_b--;
		}
	}
}

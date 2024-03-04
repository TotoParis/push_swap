/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:04:38 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:27:19 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	cost(t_stack **a, t_stack **b, int *nbr_a, int *nbr_b)
{
	t_stack	*tmp;
	int		nbr;
	int		cost;
	int		tmp_cost;

	tmp = *a;
	*nbr_a = tmp->nb;
	*nbr_b = (*b)->nb;
	cost = INT_MAX;
	while (tmp)
	{
		nbr = target_nbr_b(tmp->nb, b);
		tmp_cost = min_cost(a, b, tmp->nb, nbr);
		if (tmp_cost < cost)
		{
			cost = tmp_cost;
			*nbr_a = tmp->nb;
			*nbr_b = nbr;
		}
		tmp = tmp->next;
	}
}

int	target_nbr_b(int nbr, t_stack **b)
{
	t_stack	*tmp;
	int		nbr_b;
	int		diff;

	tmp = *b;
	nbr_b = get_max(b);
	diff = INT_MAX;
	while (tmp)
	{
		if (nbr - tmp->nb < diff && nbr > tmp->nb)
		{
			diff = nbr - tmp->nb;
			nbr_b = tmp->nb;
		}
		tmp = tmp->next;
	}
	return (nbr_b);
}

int	min_cost(t_stack **a, t_stack **b, int nbr_a, int nbr_b)
{
	t_cost	cost;
	int		id_a;
	int		id_b;

	id_a = get_id(a, nbr_a);
	id_b = get_id(b, nbr_b);
	cost.ra_rb = compare_cost(id_a, id_b);
	cost.rra_rrb = compare_cost(reverse_id(a, id_a),
			reverse_id(b, id_b));
	cost.rra_rb = reverse_id(a, id_a) + id_b ;
	cost.ra_rrb = id_a + reverse_id(b, id_b);
	return (cheaper_move(cost));
}

int	compare_cost(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	cheaper_move(t_cost cost)
{
	int	cheaper;

	cheaper = cost.ra_rb;
	if (cost.rra_rrb < cheaper)
		cheaper = cost.rra_rrb;
	if (cost.rra_rb < cheaper)
		cheaper = cost.rra_rb;
	if (cost.ra_rrb < cheaper)
		cheaper = cost.ra_rrb;
	return (cheaper);
}

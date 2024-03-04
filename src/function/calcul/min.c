/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:24:16 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:27:44 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	get_min(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	tmp = *stack;
	min = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

int	get_min_id(t_stack **stack)
{
	int		min;
	int		id;
	t_stack	*tmp;

	tmp = *stack;
	min = tmp->nb;
	id = tmp->id;
	while (tmp)
	{
		if (tmp->nb < min)
		{
			min = tmp->nb;
			id = tmp->id;
		}
		tmp = tmp->next;
	}
	return (id);
}

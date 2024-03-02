/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:46:47 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/02 17:47:59 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	get_max(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	tmp = *stack;
	max = tmp->nb;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int	get_max_id(t_stack **stack)
{
	int		max;
	int		pos;
	t_stack	*tmp;

	tmp = *stack;
	max = tmp->nb;
	pos = tmp->id;
	while (tmp)
	{
		if (tmp->nb > max)
		{
			max = tmp->nb;
			pos = tmp->id;
		}
		tmp = tmp->next;
	}
	return (pos);
}

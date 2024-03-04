/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:44:32 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:26:24 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	update_id(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->id = i + 1;
		i++;
		tmp = tmp->next;
	}
}

int	get_id(t_stack **stack, int nbr)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->nb == nbr)
			break ;
		tmp = tmp->next;
	}
	return (tmp->id);
}

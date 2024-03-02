/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:24:39 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/02 17:37:22 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	median(t_stack **stack)
{
	int	len;
	int	median;

	len = ft_stklast(*stack)->id;
	if (len % 2 == 0)
		median = len / 2;
	else
		median = (len / 2) + 1;
	return (median);
}

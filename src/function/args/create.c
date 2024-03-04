/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:13:06 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:51:05 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	return (0);
}

int	set_arg(char **tab, t_stack **stack, int *j)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (tab[i])
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (ft_stkclear(stack), 0);
		new->nb = (int)ft_atoi(tab[i]);
		new->id = *j + 1;
		new->next = NULL;
		if (!*stack)
			ft_stkadd_front(stack, new);
		else
			ft_stkadd_back(stack, new);
		(*j)++;
		i++;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("id: %d, nb: %d\n", tmp->id, tmp->nb);
		tmp = tmp->next;
	}
}

t_stack	*parse_args(char **args)
{	
	int		i;
	int		j;
	char	**tab;
	t_stack	*stack;

	i = 1;
	j = 0;
	stack = NULL;
	while (args[i])
	{
		tab = malloc(sizeof(*tab) * 2);
		tab[0] = ft_strdup(args[i]);
		tab[1] = NULL;
		if (!check_args(tab))
			return (clear_tab(tab), NULL);
		if (!set_arg(tab, &stack, &j))
			return (clear_tab(tab), NULL);
		clear_tab(tab);
		i++;
	}
	return (stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:27:23 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/04 12:21:36 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	ft_itemcount(char const *s)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i])
	{
		if ((!is_space(s[i]) && is_space(s[i + 1]))
			|| (!s[i + 1] && !is_space(s[i])))
			l++;
		i++;
	}
	return (l);
}

static void	ft_garbage(char **r)
{
	int	i;

	i = -1;
	while (r[i++])
		free(r[i]);
	free(r[i]);
	free(r);
	return ;
}

static void	ft_itemplace(char const *s, char **r)
{
	int		i;
	int		j;
	int		x;

	i = -1;
	x = 0;
	while (s[++i])
	{
		if (is_space(s[i]))
			continue ;
		j = i;
		while (!is_space(s[j]) && s[j])
			j++;
		r[x] = ft_substr(s, i, (j - i));
		if (!r[x])
		{
			ft_garbage(r);
			return ;
		}
		x++;
		i = j - 1;
	}
}

char	**ft_split(char const *s)
{
	char	**r;

	if (!s)
		return (0);
	r = ft_calloc((ft_itemcount(s) + 1), sizeof(char *));
	if (!r)
		return (0);
	ft_itemplace(s, r);
	return (r);
}

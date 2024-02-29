/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:26:42 by tbarret           #+#    #+#             */
/*   Updated: 2023/12/05 10:50:13 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len < ft_strlen(s))
		r = ft_calloc(((len + 1)), sizeof(char));
	else
		r = ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	if (!r)
		return (0);
	while (s[start] && i < len)
	{
		r[i] = s[start];
		start++;
		i++;
	}
	r[i] = '\0';
	return (r);
}

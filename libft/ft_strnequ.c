/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 06:17:55 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 01:42:30 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t size)
{
	size_t	cmpt;

	if (!s1 || !s2)
		return (0);
	cmpt = 0;
	while (s1[cmpt] && s2[cmpt] && cmpt < size)
	{
		if (s1[cmpt] != s2[cmpt])
			return (0);
		cmpt++;
	}
	if (cmpt == size)
		cmpt--;
	if (s1[cmpt] == s2[cmpt])
		return (1);
	return (0);
}

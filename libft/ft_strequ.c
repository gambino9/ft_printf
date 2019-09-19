/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 06:03:37 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 01:41:45 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	cmpt;

	cmpt = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[cmpt] && s2[cmpt])
	{
		if (s1[cmpt] != s2[cmpt])
			return (0);
		cmpt++;
	}
	if (s1[cmpt] == s2[cmpt])
		return (1);
	return (0);
}

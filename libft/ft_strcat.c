/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:02:32 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/14 01:39:42 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t cmpt;
	size_t cmpt2;

	cmpt = 0;
	cmpt2 = 0;
	while (s1[cmpt])
		cmpt++;
	while (s2[cmpt2])
	{
		s1[cmpt] = s2[cmpt2];
		cmpt++;
		cmpt2++;
	}
	s1[cmpt] = 0;
	return (s1);
}

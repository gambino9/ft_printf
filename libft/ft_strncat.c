/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:11:13 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/14 01:40:08 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t cmpt;
	size_t cmpt2;

	cmpt = 0;
	cmpt2 = 0;
	while (s1[cmpt])
		cmpt++;
	while (s2[cmpt2] && n > cmpt2)
	{
		s1[cmpt] = s2[cmpt2];
		cmpt++;
		cmpt2++;
	}
	s1[cmpt] = 0;
	return (s1);
}

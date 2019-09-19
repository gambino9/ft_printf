/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 05:41:23 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/15 02:26:51 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			cmpt;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	cmpt = 0;
	while (cmpt < n)
	{
		if (str1[cmpt] != str2[cmpt])
			return (str1[cmpt] - str2[cmpt]);
		cmpt++;
	}
	return (0);
}

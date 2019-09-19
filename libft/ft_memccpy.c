/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:25:50 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 03:01:27 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			cmpt;
	unsigned char	*desti;
	unsigned char	*srce;

	desti = (unsigned char *)dst;
	srce = (unsigned char *)src;
	cmpt = 0;
	while (cmpt < n)
	{
		desti[cmpt] = srce[cmpt];
		if (desti[cmpt] == (unsigned char)c)
			return (desti + cmpt + 1);
		cmpt++;
	}
	return (NULL);
}

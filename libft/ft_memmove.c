/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:48:41 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 01:00:17 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		cmpt;
	char		*dest;
	const char	*srce;

	dest = dst;
	srce = src;
	cmpt = 0;
	if (dest > srce)
	{
		cmpt = len;
		while (cmpt > 0)
		{
			dest[cmpt - 1] = srce[cmpt - 1];
			cmpt--;
		}
	}
	else if (dest < srce)
		ft_memcpy(dest, srce, len);
	return (dst);
}

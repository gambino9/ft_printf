/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:00:21 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 00:59:37 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		cmpt;
	char		*desti;
	const char	*srce;

	desti = dst;
	srce = src;
	cmpt = 0;
	while (cmpt < n)
	{
		desti[cmpt] = srce[cmpt];
		cmpt++;
	}
	return (dst);
}

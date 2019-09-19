/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:22:56 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/08 23:32:06 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	cmpt;

	cmpt = 0;
	while (src[cmpt])
	{
		dst[cmpt] = src[cmpt];
		cmpt++;
	}
	dst[cmpt] = 0;
	return (dst);
}

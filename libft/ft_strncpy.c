/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 00:46:15 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 02:46:27 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t cmpt;

	cmpt = 0;
	while (src[cmpt] && cmpt < len)
	{
		dest[cmpt] = src[cmpt];
		cmpt++;
	}
	while (cmpt < len)
	{
		dest[cmpt] = '\0';
		cmpt++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:18:31 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/14 01:40:44 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_size;

	i = 0;
	while (dst[i])
		i++;
	dest_size = i;
	j = 0;
	while (src[j] && j < size - dest_size - 1 && dest_size < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	while (src[j])
		j++;
	if (dest_size < size)
		return (dest_size + j);
	return (size + j);
}

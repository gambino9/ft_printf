/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 22:26:22 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 01:43:41 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	size_t	size;
	size_t	cmpt;
	char	*str;

	if (!s1)
		return (0);
	size = (size_t)start;
	cmpt = 0;
	if (!(str = ft_strnew(len)))
		return (0);
	while (len)
	{
		str[cmpt] = s1[size];
		size++;
		cmpt++;
		len--;
	}
	if (len == 0)
		return (str);
	return (0);
}

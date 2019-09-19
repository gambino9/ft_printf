/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 01:04:39 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 05:57:15 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	char	*hay;
	char	*nee;
	char	*str;

	hay = (char *)haystack;
	nee = (char *)needle;
	if (!*nee && loc)
		return (hay);
	while (*hay && loc)
	{
		nee = (char *)needle;
		str = (char *)ft_strsub(hay, 0, loc--);
		while (*str && *nee && *str == *nee)
		{
			str++;
			nee++;
		}
		if (!*nee)
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:16:25 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 05:42:45 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char		*str;
	char			*hay;

	hay = (char *)haystack;
	str = needle;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*haystack)
	{
		while (*haystack && *needle && *haystack == *needle)
		{
			haystack++;
			needle++;
		}
		if (!*needle)
			return ((char *)haystack - ft_strlen(str));
		haystack = ++hay;
		needle = str;
	}
	return (NULL);
}

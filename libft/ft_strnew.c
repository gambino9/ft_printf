/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnezw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 05:09:03 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 02:15:13 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	cmpt;

	cmpt = 0;
	if (!(str = (char *)malloc(size * sizeof(char) + 1)))
		return (NULL);
	while (cmpt < size)
	{
		str[cmpt] = '\0';
		cmpt++;
	}
	str[cmpt] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 05:17:27 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 01:00:31 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tbl;
	size_t	cmpt;

	cmpt = 0;
	tbl = (void *)s;
	while (cmpt < n)
	{
		if (tbl[cmpt] == (char)c)
			return (&tbl[cmpt]);
		cmpt++;
	}
	return (NULL);
}

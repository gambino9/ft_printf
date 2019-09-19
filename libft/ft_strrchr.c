/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:18:51 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/09 22:28:50 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		cmpt;
	int		cmpt2;

	cmpt = 0;
	cmpt2 = 0;
	str = (char *)s;
	while (*str != '\0')
	{
		str++;
		cmpt++;
	}
	while (cmpt > cmpt2 && *str != c)
	{
		str--;
		cmpt--;
	}
	if (cmpt == cmpt2 && *str != c)
		return (NULL);
	return (str);
}

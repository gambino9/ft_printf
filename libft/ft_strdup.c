/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:50:37 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/27 23:32:56 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		cmpt;

	cmpt = 0;
	while (s1[cmpt])
		cmpt++;
	if (!(copy = (char*)malloc((cmpt + 1) * sizeof(char))))
		return (0);
	cmpt = 0;
	while (s1[cmpt])
	{
		copy[cmpt] = s1[cmpt];
		cmpt++;
	}
	copy[cmpt] = 0;
	return (copy);
}

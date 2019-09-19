/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:49:03 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 02:03:39 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		cmpt;

	if (!s1 || !s2)
		return (0);
	cmpt = 0;
	if (!(s3 = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char))))
		return (NULL);
	while (*s1)
	{
		s3[cmpt] = *s1;
		cmpt++;
		s1++;
	}
	while (*s2)
	{
		s3[cmpt] = *s2;
		cmpt++;
		s2++;
	}
	s3[cmpt] = '\0';
	return (s3);
}

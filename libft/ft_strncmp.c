/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 01:45:15 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/11 02:01:10 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cmpt;

	cmpt = 0;
	if (n == 0)
		return (0);
	while (s1[cmpt] == s2[cmpt] && s1[cmpt] != '\0' && s2[cmpt] != '\0'
	&& cmpt < n)
		cmpt++;
	if (cmpt == n)
		cmpt--;
	return ((unsigned char)s1[cmpt] - (unsigned char)s2[cmpt]);
}

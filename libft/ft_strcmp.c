/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 01:28:00 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/11 01:47:41 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int cmpt;

	cmpt = 0;
	while (s1[cmpt] == s2[cmpt] && s1[cmpt] != '\0' && s2[cmpt] != '\0')
		cmpt++;
	return ((unsigned char)s1[cmpt] - (unsigned char)s2[cmpt]);
}

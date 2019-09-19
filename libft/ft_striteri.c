/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 05:40:38 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 01:40:31 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	cmpt;

	cmpt = 0;
	if (s && f)
	{
		while (s[cmpt])
		{
			(*f)(cmpt, &s[cmpt]);
			cmpt++;
		}
	}
}

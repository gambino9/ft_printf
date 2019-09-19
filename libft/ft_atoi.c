/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:04:45 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/12 23:57:25 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			signe;
	long int	nbr;
	int			cmpt;

	cmpt = 0;
	signe = 1;
	nbr = 0;
	while (str[cmpt] == '\t' || str[cmpt] == '\v' || str[cmpt] == '\n'
	|| str[cmpt] == '\r' || str[cmpt] == '\f' || str[cmpt] == ' ')
		cmpt++;
	if (str[cmpt] == '-' || str[cmpt] == '+')
	{
		if (str[cmpt] == '-')
			signe = -1;
		cmpt++;
	}
	while (str[cmpt] >= '0' && str[cmpt] <= '9')
	{
		nbr = nbr * 10 + str[cmpt] - '0';
		cmpt++;
	}
	return (nbr * signe);
}

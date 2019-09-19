/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 04:21:56 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/24 23:31:43 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrnbr(int n)
{
	int	cmpt;

	cmpt = 0;
	if (n == 0)
		return (2);
	while (n)
	{
		n = n / 10;
		cmpt++;
	}
	cmpt++;
	return (cmpt);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	int		sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	nbr = ft_nbrnbr(n) + sign;
	if (!(str = malloc(nbr * sizeof(char))))
		return (NULL);
	str[--nbr] = '\0';
	while (nbr--)
	{
		str[nbr] = n % 10 + '0';
		n /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

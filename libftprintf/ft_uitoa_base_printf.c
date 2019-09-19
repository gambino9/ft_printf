/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:25:43 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/03 23:23:07 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_uitoa_base_printf(uintmax_t nbr, int base, char x)
{
	int			len;
	uintmax_t	nbr2;
	char		*mall;
	char		*ret;

	len = 1;
	nbr2 = nbr;
	while (nbr2 /= base)
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	mall = (x == 'X') ?
		ft_strdup("0123456789ABCDEF") : ft_strdup("0123456789abcdef");
	ret[len] = '\0';
	while (len-- > 0)
	{
		ret[len] = mall[nbr % base];
		nbr /= base;
	}
	len = ft_strlen(ret);
	write(1, ret, len);
	free(mall);
	free(ret);
	return (len);
}

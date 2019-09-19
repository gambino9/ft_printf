/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 23:05:19 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/27 19:37:46 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nbr_len_base(intmax_t nbr, int base)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < -9223372036854775807)
		return (20);
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

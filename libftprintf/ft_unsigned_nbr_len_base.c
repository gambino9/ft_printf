/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nbr_len_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:51:15 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/29 22:06:11 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigned_nbr_len_base(uintmax_t nbr, int base)
{
	int		cmpt;

	cmpt = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		cmpt++;
	}
	return (cmpt);
}

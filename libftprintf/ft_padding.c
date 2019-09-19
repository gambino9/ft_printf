/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:24:11 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/02 21:27:13 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding_left(int nbrlen, t_struct *info)
{
	while (info->width >= nbrlen)
	{
		info->total += write(1, " ", 1);
		info->width--;
	}
}

void	ft_padding_right(int nbrlen, int n, t_struct *info)
{
	if (!info->precision_find)
		while (info->width-- > nbrlen)
		{
			if (info->zero)
				info->total += write(1, "0", 1);
			else
				info->total += write(1, " ", 1);
		}
	else
	{
		if (info->plus)
			info->width--;
		while (info->width-- > info->precision)
		{
			if ((info->zero && info->width != info->precision) || n == 1)
				info->total += write(1, "0", 1);
			else
				info->total += write(1, " ", 1);
		}
	}
}

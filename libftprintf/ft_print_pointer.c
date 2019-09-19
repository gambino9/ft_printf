/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:32:41 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/01 04:43:25 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_pointer_left(uintmax_t nbr, t_struct *info)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len_base(nbr, 16) + 2;
	info->total += write(1, "0x", 2);
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
		return ;
	info->width = (info->precision >= nbrlen) ?
		info->width - (info->precision + 2) : info->width - nbrlen;
	while (info->precision > (nbrlen - 2))
	{
		info->total += write(1, "0", 1);
		info->precision -= 1;
	}
	info->total += ft_uitoa_base_printf(nbr, 16, 0);
	while (info->width > 0)
	{
		info->total += write(1, " ", 1);
		info->width -= 1;
	}
}

void			ft_print_pointer_right(uintmax_t nbr, t_struct *info)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len_base(nbr, 16) + 2;
	info->width = (info->precision >= nbrlen) ?
		info->width - (info->precision + 2) : info->width - nbrlen;
	while (info->width > 0)
	{
		info->total += write(1, " ", 1);
		info->width -= 1;
	}
	info->total += write(1, "0x", 2);
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
		return ;
	while (info->precision > (nbrlen - 2))
	{
		info->total += write(1, "0", 1);
		info->precision -= 1;
	}
	info->total += ft_uitoa_base_printf(nbr, 16, 0);
}

void			ft_print_pointer(const char *str, t_struct *info, va_list ap)
{
	uintmax_t	nbr;

	if (str[info->cmpt] == 'p')
		nbr = (long long)va_arg(ap, void *);
	if (info->minus)
		ft_print_pointer_left(nbr, info);
	else
		ft_print_pointer_right(nbr, info);
}

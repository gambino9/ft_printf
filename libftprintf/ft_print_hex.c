/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:22:00 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/02 19:42:20 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_hex_left(uintmax_t nbr, t_struct *info, char x)
{
	int			nbrlen;

	nbrlen = ft_unsigned_nbr_len_base(nbr, 16);
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
	{
		while (info->width > 0)
		{
			info->total += write(1, " ", 1);
			info->width -= 1;
		}
		return ;
	}
	if (info->hash == 1 && nbr != 0)
		info->width -= 2;
	if (info->hash == 1 && x == 'x' && nbr != 0)
		info->total += write(1, "0x", 2);
	else if (info->hash == 1 && x == 'X' && nbr != 0)
		info->total += write(1, "0X", 2);
	while (nbrlen++ < info->precision)
		info->total += write(1, "0", 1);
	info->total += ft_uitoa_base_printf(nbr, 16, x);
	while (info->width-- >= nbrlen)
		info->total += write(1, " ", 1);
}

void			ft_padding_x(int nbrlen, t_struct *info)
{
	if (info->precision_find == 0)
		while (info->width-- > nbrlen)
		{
			if (info->zero == 1)
				info->total += write(1, "0", 1);
			else
				info->total += write(1, " ", 1);
		}
	else
	{
		while (nbrlen < info->precision)
			nbrlen++;
		if (info->zero == 1)
			info->width--;
		while (info->width-- > nbrlen)
		{
			if (info->zero == 1)
				info->total += write(1, "0", 1);
			else
				info->total += write(1, " ", 1);
		}
	}
}

void			ft_x(uintmax_t nbr, char x, t_struct *info)
{
	if (info->hash == 1 && x == 'x' && nbr != 0)
		info->total += write(1, "0x", 2);
	else if (info->hash == 1 && x == 'X' && nbr != 0)
		info->total += write(1, "0X", 2);
}

void			ft_print_hex_right(uintmax_t nbr, t_struct *info, char x)
{
	int			nbrlen;

	nbrlen = ft_unsigned_nbr_len_base(nbr, 16);
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
	{
		while (info->width)
		{
			info->total += write(1, " ", 1);
			info->width -= 1;
		}
		return ;
	}
	if (info->hash == 1 && nbr != 0)
		info->width -= 2;
	if (info->hash == 1 && info->zero == 1)
		ft_x(nbr, x, info);
	ft_padding_x(nbrlen, info);
	if (info->hash == 1 && info->zero == 0)
		ft_x(nbr, x, info);
	while (nbrlen++ < info->precision)
		info->total += write(1, "0", 1);
	info->total += ft_uitoa_base_printf(nbr, 16, x);
}

void			ft_print_hex(const char *str, t_struct *info, va_list ap)
{
	uintmax_t	nbr;
	char		x;

	if (str[info->cmpt] == 'x')
		x = 'x';
	else
		x = 'X';
	if (str[info->cmpt] == 'x' || str[info->cmpt] == 'X')
	{
		if (info->length == 0)
			nbr = va_arg(ap, unsigned int);
		else if (info->length == 2)
			nbr = (unsigned char)va_arg(ap, unsigned int);
		else if (info->length == 1)
			nbr = (unsigned short)va_arg(ap, unsigned int);
		else if (info->length == 3)
			nbr = va_arg(ap, unsigned long);
		else if (info->length == 4)
			nbr = va_arg(ap, unsigned long long);
		if (info->minus == 1)
			ft_print_hex_left(nbr, info, x);
		else
			ft_print_hex_right(nbr, info, x);
	}
}

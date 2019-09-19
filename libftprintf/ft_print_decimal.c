/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 04:45:04 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/04 03:43:42 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_left2(t_struct *info, int save)
{
	while (info->width > save)
	{
		info->total += write(1, " ", 1);
		info->width--;
	}
}

void			ft_print_left(intmax_t nbr, t_struct *info)
{
	int			neg;
	int			nbrlen;
	int			save;

	if (ft_print_zero(info, nbr) == 1)
		return ;
	neg = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	nbrlen = ft_nbr_len_base(nbr, 10);
	if (info->space && neg == 0)
		info->total += write(1, " ", 1);
	if (neg == 1)
		info->total += write(1, "-", 1);
	if (info->plus && neg == 0)
		info->total += write(1, "+", 1);
	if (info->plus || neg == 1 || info->space)
		info->width--;
	save = (nbrlen > info->precision) ? nbrlen : info->precision;
	while (info->precision > nbrlen++)
		info->total += write(1, "0", 1);
	info->total += ft_itoa_base_printf(nbr, 10);
	ft_print_left2(info, save);
}

void			ft_print_right2(intmax_t nbr, int neg, int n, t_struct *info)
{
	int			s;

	s = (neg == 1 || info->plus
			|| (info->space && info->precision > n)) ? 1 : 0;
	info->width -= s;
	if (info->precision_find && info->precision > n)
	{
		while (info->width > info->precision)
		{
			info->total += write(1, " ", 1);
			info->width--;
		}
	}
	else
	{
		while (info->width > n)
		{
			if (!info->zero || (info->space && neg == 0))
				info->total += write(1, " ", 1);
			else
				info->total += write(1, "0", 1);
			info->space = 0;
			info->width--;
		}
	}
}

void			ft_print_right(intmax_t nbr, t_struct *info)
{
	int			nbrlen;
	int			neg;

	if (ft_print_zero(info, nbr) == 1)
		return ;
	neg = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	nbrlen = ft_nbr_len_base(nbr, 10);
	if (info->width && !info->zero)
		ft_print_right2(nbr, neg, nbrlen, info);
	if (neg == 1)
		info->total += write(1, "-", 1);
	if (info->plus && neg == 0)
		info->total += write(1, "+", 1);
	if (info->space && neg == 0)
		info->total += write(1, " ", 1);
	if (info->width)
		ft_print_right2(nbr, neg, nbrlen, info);
	while (info->precision > nbrlen++)
		info->total += write(1, "0", 1);
	info->total += ft_itoa_base_printf(nbr, 10);
}

void			ft_print_decimal(const char *str, t_struct *info, va_list ap)
{
	intmax_t	nbr;

	if (str[info->cmpt] == 'd' || str[info->cmpt] == 'i')
	{
		if (info->length == 0)
			nbr = va_arg(ap, int);
		else if (info->length == 2)
			nbr = (signed char)va_arg(ap, int);
		else if (info->length == 1)
			nbr = (short)va_arg(ap, int);
		else if (info->length == 3)
			nbr = va_arg(ap, long);
		else if (info->length == 4)
			nbr = va_arg(ap, long long);
		if (info->minus == 1)
			ft_print_left(nbr, info);
		else
			ft_print_right(nbr, info);
	}
}

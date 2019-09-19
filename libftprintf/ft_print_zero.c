/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 02:57:05 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/04 03:44:22 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_left_z(t_struct *info)
{
	int	save;

	if (info->space)
		info->total += write(1, " ", 1);
	if (info->plus)
		info->total += write(1, "+", 1);
	if (info->space || info->plus)
		info->width--;
	save = info->precision;
	while (info->precision > 0)
	{
		info->total += write(1, "0", 1);
		info->precision--;
	}
	if (info->precision_find == 0)
	{
		info->total += write(1, "0", 1);
		info->width--;
	}
	while (info->width > save)
	{
		info->total += write(1, " ", 1);
		info->width--;
	}
}

void	ft_print_right_z2(t_struct *info)
{
	if (info->width)
	{
		while (info->width > info->precision)
		{
			if (info->zero && info->precision_find == 0)
				info->total += write(1, "0", 1);
			else
				info->total += write(1, " ", 1);
			info->width--;
		}
	}
}

void	ft_print_right_z(t_struct *info)
{
	if (info->plus || info->space)
		info->width--;
	if (info->precision_find == 0)
		info->width--;
	if (info->width && !info->zero)
		ft_print_right_z2(info);
	if (info->plus)
		info->total += write(1, "+", 1);
	if (info->space)
		info->total += write(1, " ", 1);
	if (info->width)
		ft_print_right_z2(info);
	while (info->precision > 0)
	{
		info->total += write(1, "0", 1);
		info->precision--;
	}
	if (info->precision_find == 0)
		info->total += write(1, "0", 1);
}

int		ft_print_zero(t_struct *info, intmax_t nbr)
{
	if (nbr == 0)
	{
		if (info->minus == 0)
			ft_print_right_z(info);
		if (info->minus == 1)
			ft_print_left_z(info);
		return (1);
	}
	return (0);
}

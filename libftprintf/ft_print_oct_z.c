/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:32:00 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/04 03:30:42 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_oct_right_z2(t_struct *info)
{
	if (info->width)
	{
		while (info->width > 0)
		{
			if (info->zero && info->precision_find == 0)
				info->total += write(1, "0", 1);
			else
				info->total += write(1, " ", 1);
			info->width--;
		}
	}
}

void	ft_print_oct_z_right(t_struct *info)
{
	if ((info->hash && !info->precision) || (!info->precision_find))
		info->width--;
	info->width -= info->precision;
	ft_print_oct_right_z2(info);
	if ((info->hash && !info->precision) || (!info->precision_find))
		info->total += write(1, "0", 1);
	while (info->precision > 0)
	{
		info->total += write(1, "0", 1);
		info->precision--;
	}
}

void	ft_print_oct_z_left2(t_struct *info)
{
	while (info->precision > 0)
	{
		info->total += write(1, "0", 1);
		info->precision--;
		info->width--;
	}
}

void	ft_print_oct_z_left(t_struct *info)
{
	int	save;

	if (info->hash && info->precision_find)
	{
		info->total += write(1, "0", 1);
		info->width--;
		info->precision--;
	}
	save = info->precision;
	ft_print_oct_z_left2(info);
	if (info->precision_find == 0)
	{
		info->total += write(1, "0", 1);
		info->width--;
	}
	while (info->width > 0)
	{
		info->total += write(1, " ", 1);
		info->width--;
	}
}

int		ft_print_oct_z(uintmax_t nbr, t_struct *info)
{
	if (nbr == 0)
	{
		if (info->minus)
			ft_print_oct_z_left(info);
		else
			ft_print_oct_z_right(info);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 07:02:33 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/01 04:37:24 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_left_char(unsigned char c, t_struct *info)
{
	info->total += write(1, &c, 1);
	while (info->width > 1)
	{
		info->total += write(1, " ", 1);
		info->width -= 1;
	}
}

void				ft_print_right_char(unsigned char c, t_struct *info)
{
	while (info->width > 1)
	{
		if (info->zero == 1)
			info->total += write(1, "0", 1);
		else
			info->total += write(1, " ", 1);
		info->width -= 1;
	}
	info->total += write(1, &c, 1);
}

void				ft_print_char(const char *str, t_struct *info, va_list ap)
{
	unsigned char	c;

	if (str[info->cmpt] == 'c')
		c = (unsigned char)va_arg(ap, int);
	if (info->minus == 1)
		ft_print_left_char(c, info);
	else
		ft_print_right_char(c, info);
}

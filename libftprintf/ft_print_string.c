/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 07:15:49 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/01 04:45:52 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_string_left(char *string, t_struct *info)
{
	int strlen;

	if (!string)
		string = "(null)";
	strlen = ft_strlen(string);
	if (info->precision_find == 1 && strlen > 0 && strlen > info->precision)
		strlen = info->precision;
	info->total += write(1, string, strlen);
	while (info->width > strlen)
	{
		info->total += write(1, " ", 1);
		info->width -= 1;
	}
}

void		ft_print_string_right(char *string, t_struct *info)
{
	int		strlen;

	if (!string)
		string = "(null)";
	strlen = ft_strlen(string);
	if (info->precision_find == 1 && strlen > 0 && strlen > info->precision)
		strlen = info->precision;
	while (info->width > strlen)
	{
		if (info->zero == 1)
			info->total += write(1, "0", 1);
		else
			info->total += write(1, " ", 1);
		info->width -= 1;
	}
	info->total += write(1, string, strlen);
}

void		ft_print_string(const char *str, t_struct *info, va_list ap)
{
	char	*string;

	if (str[info->cmpt] == 's')
		string = va_arg(ap, char *);
	if (info->minus == 1)
		ft_print_string_left(string, info);
	else
		ft_print_string_right(string, info);
}

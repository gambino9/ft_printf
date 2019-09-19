/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 00:59:01 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/04 19:52:41 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lenght(const char *str, t_struct *info)
{
	if (ft_strchr("hlL", str[info->cmpt]))
	{
		if (str[info->cmpt] == 'h')
		{
			if (str[info->cmpt + 1] == 'h')
				info->length = 2;
			else
				info->length = 1;
		}
		else if (str[info->cmpt] == 'l')
		{
			if (str[info->cmpt + 1] == 'l')
				info->length = 4;
			else
				info->length = 3;
		}
		else if (str[info->cmpt] == 'L')
			info->length = 5;
		while (ft_strchr("hlL", str[info->cmpt]))
			info->cmpt++;
	}
	if (ft_strchr("diouxXcsp%", str[info->cmpt]))
		info->found = 1;
}

void	ft_precision(const char *str, t_struct *info, va_list ap)
{
	int	tmp_pre;

	if (str[info->cmpt] == '.')
	{
		info->precision_find = 1;
		info->cmpt++;
		if (ft_isdigit(str[info->cmpt]))
			info->precision = ft_atoi(&str[info->cmpt]);
		else if (str[info->cmpt] == '*')
		{
			tmp_pre = va_arg(ap, int);
			if (tmp_pre >= 0)
				info->precision = tmp_pre;
			else
				info->precision_find = 0;
		}
		while (str[info->cmpt] == '*' || ft_isdigit(str[info->cmpt]))
			info->cmpt++;
	}
}

void	ft_width(const char *str, t_struct *info, va_list ap)
{
	while (ft_isdigit(str[info->cmpt]) || (str[info->cmpt] == '*'))
	{
		if (ft_isdigit(str[info->cmpt]))
		{
			info->width = ft_atoi(&str[info->cmpt]);
			while (ft_isdigit(str[info->cmpt]))
				info->cmpt++;
		}
		if (str[info->cmpt] == '*')
		{
			info->width = va_arg(ap, int);
			info->minus = (info->width < 0) ? 1 : info->minus;
			info->width = (info->width < 0) ? -info->width : info->width;
			info->cmpt++;
		}
	}
}

void	ft_flag(const char *str, t_struct *info)
{
	while (str[info->cmpt] == '#' || str[info->cmpt] == '0'
	|| str[info->cmpt] == '-' || str[info->cmpt] == '+'
	|| str[info->cmpt] == ' ')
	{
		if (str[info->cmpt] == '#')
			info->hash = 1;
		if (str[info->cmpt] == '0')
			info->zero = 1;
		if (str[info->cmpt] == '-')
			info->minus = 1;
		if (str[info->cmpt] == '+')
			info->plus = 1;
		if (str[info->cmpt] == ' ')
			info->space = 1;
		info->cmpt++;
	}
	if (info->plus == 1)
		info->space = 0;
	if (info->minus == 1)
		info->zero = 0;
}

void	ft_parsing(const char *str, t_struct *info, va_list ap)
{
	int		iteration;

	iteration = 0;
	info->cmpt++;
	while (info->found == 0 && iteration < 100 && str[info->cmpt])
	{
		ft_flag(str, info);
		ft_width(str, info, ap);
		ft_precision(str, info, ap);
		ft_lenght(str, info);
		iteration++;
	}
	if (iteration == 100 && info->found == 0)
	{
		info->cmpt = 0;
		while (str[info->cmpt])
		{
			write(1, &str[info->cmpt], 1);
			info->cmpt++;
		}
	}
	if (info->found == 1 && ft_strchr("diouxX", str[info->cmpt])
			&& info->precision_find == 1)
		info->zero = 0;
}

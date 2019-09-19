/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:22:36 by clboutry          #+#    #+#             */
/*   Updated: 2019/09/04 00:38:10 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef	struct	s_struct
{
	int			cmpt;
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			precision_find;
	int			length;
	int			found;
	char		*atoi;
	int			total;
}				t_struct;

void			ft_printf_2(const char *str, ...);
void			ft_parsing(const char *str, t_struct *info, va_list ap);
void			ft_print_decimal(const char *str, t_struct *info, va_list ap);
int				ft_nbr_len_base(intmax_t nbr, int base);
int				ft_itoa_base_printf(intmax_t nbr, int base);
void			ft_padding_left(int nbrlen, t_struct *info);
void			ft_padding_right(int nbrlen, int neg, t_struct *info);
void			ft_print_char(const char *str, t_struct *info, va_list ap);
void			ft_print_string(const char *str, t_struct *info, va_list ap);
void			ft_print_pointer(const char *str, t_struct *info, va_list ap);
int				ft_uitoa_base_printf(uintmax_t nbr, int base, char x);
int				ft_unsigned_nbr_len_base(uintmax_t nbr, int base);
void			ft_print_percent(const char *str, t_struct *info);
void			ft_print_hex(const char *str, t_struct *info, va_list ap);
void			ft_print_oct(const char *str, t_struct *info, va_list ap);
void			ft_print_unsigned(const char *str, t_struct *info, va_list ap);
int				ft_print_zero(t_struct *info, intmax_t nbr);
int				ft_print_oct_z(uintmax_t nbr, t_struct *info);
#endif

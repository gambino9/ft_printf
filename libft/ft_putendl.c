/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:36:40 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/23 22:44:03 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int		cmpt;

	cmpt = 0;
	while (s[cmpt])
	{
		write(1, &s[cmpt], 1);
		cmpt++;
	}
	write(1, "\n", 1);
}

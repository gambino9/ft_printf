/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 03:05:04 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/24 03:08:01 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int	cmpt;

	cmpt = 0;
	while (s[cmpt])
	{
		write(fd, &s[cmpt], 1);
		cmpt++;
	}
	write(fd, "\n", 1);
}

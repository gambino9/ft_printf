/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:04:58 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 02:02:59 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_while(int cmpt2, char const *s)
{
	while (s[cmpt2 + 1])
		cmpt2++;
	while (s[cmpt2] == '\t' || s[cmpt2] == '\n' || s[cmpt2] == ' ')
		cmpt2--;
	return (cmpt2);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		cmpt;
	int		cmpt2;
	int		cmpt3;

	if (!s)
		return (0);
	cmpt = 0;
	cmpt2 = 0;
	cmpt3 = -1;
	while ((s[cmpt] == '\t' || s[cmpt] == '\n' || s[cmpt] == ' ') && s[cmpt])
		cmpt++;
	if (s[cmpt] == '\0')
		return (ft_strnew(cmpt));
	cmpt2 = ft_while(cmpt2, s);
	if (!(str = malloc((cmpt2 - cmpt + 2) * sizeof(char))))
		return (NULL);
	while (cmpt != cmpt2 + 1)
	{
		str[++cmpt3] = s[cmpt];
		cmpt++;
	}
	str[cmpt3 + 1] = '\0';
	return (str);
}

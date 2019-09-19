/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:39:32 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 02:12:07 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrwords(char const *s, char c)
{
	int cmpt;
	int pos;

	cmpt = 0;
	pos = 0;
	while (s[pos])
	{
		if (s[pos] != c && (s[pos - 1] == c || pos == 0))
			cmpt++;
		pos++;
	}
	return (cmpt);
}

static char		**ft_taille(char **str, const char *s, char c)
{
	int	pos;
	int	postab;
	int	cmpt;

	pos = 0;
	postab = 0;
	cmpt = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			pos++;
		else
		{
			while (s[pos] != c && s[pos])
			{
				pos++;
				cmpt++;
			}
			if (!(str[postab] = (char*)malloc(sizeof(char) * (cmpt + 1))))
				return (NULL);
			postab++;
			cmpt = 0;
		}
	}
	return (str);
}

static char		**ft_insert(char **str, char const *s, char c)
{
	int	pos;
	int	j;
	int	k;

	pos = 0;
	j = 0;
	k = 0;
	while (s[pos])
	{
		if (s[pos] == c && s[pos])
			pos++;
		else
		{
			while (s[pos] != c && s[pos])
				str[j][k++] = s[pos++];
			str[j][k] = '\0';
			k = 0;
			j++;
		}
	}
	str[j] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		nbrw;
	int		pos;

	if (!s)
		return (0);
	nbrw = ft_nbrwords(s, c);
	pos = 0;
	if (!(str = malloc((nbrw + 1) * sizeof(char *))))
		return (0);
	str = ft_taille(str, s, c);
	str = ft_insert(str, s, c);
	return (str);
}

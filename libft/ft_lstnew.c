/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 04:12:16 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 01:29:38 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nouv;

	if (!(nouv = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		nouv->content = NULL;
		nouv->content_size = 0;
	}
	else
	{
		if (!(nouv->content = malloc(content_size)))
		{
			free(nouv);
			return (NULL);
		}
		ft_memcpy(nouv->content, content, content_size);
		nouv->content_size = content_size;
	}
	nouv->next = NULL;
	return (nouv);
}

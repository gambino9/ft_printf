/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:03:11 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/24 23:27:56 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nouv;
	t_list	*cmpt;
	t_list	*debut;

	if (!lst || !f)
		return (NULL);
	cmpt = f(lst);
	if (!(nouv = ft_lstnew(cmpt->content, cmpt->content_size)))
		return (NULL);
	debut = nouv;
	lst = lst->next;
	while (lst)
	{
		cmpt = f(lst);
		if (!(nouv->next = ft_lstnew(cmpt->content, cmpt->content_size)))
			return (NULL);
		nouv = nouv->next;
		lst = lst->next;
	}
	return (debut);
}

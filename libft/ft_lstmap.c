/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:28:47 by roliveir          #+#    #+#             */
/*   Updated: 2019/02/03 10:32:03 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *mlist;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	mlist = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(mlist->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		mlist = mlist->next;
	}
	return (new);
}

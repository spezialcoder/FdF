/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:35:22 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/13 18:41:15 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	shred_list(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		ft_lstdelone(tmp, del);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*el;
	void	*t_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		t_content = f(lst->content);
		el = ft_lstnew(t_content);
		if (!el)
		{
			del(t_content);
			if (new_list)
				shred_list(new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, el);
		lst = lst->next;
	}
	return (new_list);
}

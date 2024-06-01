/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:04:22 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/13 18:02:21 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cptr;
	t_list	*tmp;

	cptr = *lst;
	while (cptr)
	{
		tmp = cptr;
		del(cptr->content);
		cptr = cptr->next;
		free(tmp);
	}
	*lst = NULL;
}

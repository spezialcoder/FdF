/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:21:51 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/13 18:31:03 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*root_node;

	root_node = (t_list *)malloc(sizeof(t_list));
	if (!root_node)
		return (NULL);
	root_node->content = content;
	root_node->next = NULL;
	return (root_node);
}

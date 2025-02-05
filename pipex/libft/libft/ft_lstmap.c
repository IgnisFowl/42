/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:40:43 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/10/28 11:58:18 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(t_list **new_list, void (*del)(void *))
{
	t_list	*temp;

	while (*new_list)
	{
		temp = *new_list;
		*new_list = (*new_list)->next;
		if (del)
			del(temp->content);
		free(temp);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	**last_node;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	last_node = &new_list;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_del(&new_list, del);
			return (NULL);
		}
		*last_node = new_node;
		last_node = &new_node->next;
		lst = lst->next;
	}
	return (new_list);
}

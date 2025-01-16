#include <stddef.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *content;
}                 t_list;

//add new node

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return NULL;
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

//count how many nodes there are in the list

int	ft_lstsize(t_list *lst)
{
	int i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

//add node to the front
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		return ;
}

//add node to the back
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

//del one node
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

//clear lst
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;
	t_list *next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current->next;
		del(current->content);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}
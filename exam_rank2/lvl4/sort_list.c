#include <stdlib.h>

typedef struct s_list
{
	int     data;
	t_list  *next;
} t_list;

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swap;
	t_list *start;

	start = lst; //saves start of the list

	while (lst != NULL && lst->next != NULL) //compares until the last pair
	{
		if((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = start; //goes back to the begginning of the list
		}
		else
			lst = lst->next; //no swap needed, go to next node
	}
	return (start);
}

#include <unistd.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return ;
	t_list *current = *begin_list;
	t_list *previous = NULL;
	t_list *to_free = NULL;
	while (current != NULL)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			to_free = current;
			if (previous == NULL) // this means the current node is the head
			{
				*begin_list = current->next; //move head to the next node
				current = *begin_list; //move current to new head
			}
			else
			{
				previous->next = current->next; 
				current = current->next;
			}
			free(to_free);
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}

void ft_list_remove_if2(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return ;
	t_list *current = *begin_list;
	t_list *previous = NULL;
	t_list *to_free = NULL;
	while (current != NULL)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			to_free = current;
			if (previous == NULL) // if there are no previous, node is head of the list
			{
				*begin_list = current->next; // the begginning becomes the next node
				current = *begin_list; // current becomes again the begginning
			}
			else
			{
				previous->next = current->next; // the link to the next must be linked in the previous 
				current = current->next; // current becomes the next
			}
			free(to_free);
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}
/*
if no previous
*begin_list = current->next;
current = *begin_list;

if there are previous
previous->next = current->next;
current = current->next;

if match doesn't occur
previous = current;
current = current->next;

*/
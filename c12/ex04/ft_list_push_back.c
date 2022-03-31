#include"ft_list.h"
#include<stdlib.h>
#include<stdio.h>
/*
void print_list(t_list *beta)
{
	char c;
	while (beta)
	{
		c = *((char*)beta->data);
		printf("[%c]--->\n", c);
		beta = beta->next;
	}
	
}
*/

t_list *ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *li;
	li = *begin_list;
	if (!li)
	{
		*begin_list = ft_create_elem(data);
		return(*begin_list);
	}
	else
	{
		while (li->next != NULL)
		{
			li = li->next;
		}
		li->next = ft_create_elem(data);
	}
	return(li);	
}


int main()
{
	t_list *ptr;
	t_list *ptr2;
	ptr = ft_create_elem("2");
	ptr = ft_list_push_back(&ptr,"4");
	print_list(ptr);
	while (ptr->next)
	{
		ptr2 = ptr->next;
		free(ptr);
		ptr = ptr2;
	}
	
	free(ptr);
}
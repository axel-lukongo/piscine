#include"ft_list.h"
#include<stdlib.h>
t_list *ft_list_last(t_list *begin_list)
{
	while (begin_list->next != NULL)
	{
		begin_list = begin_list->next;
	}
	return(begin_list);
}
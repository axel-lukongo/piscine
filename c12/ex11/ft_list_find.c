#include"ft_list.h"
#include<stdlib.h>
int cmp(void *data, void *data_ref)
{

	int *i = data;
	int *j = data_ref;
	if (*i == *j)
	{
		return (0);
	}
	return (1);
}

t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		
		if ((*cmp)(begin_list->data,data_ref) == 0)
		{
			print_list(begin_list);
			return(begin_list);
		}
		begin_list = begin_list->next;
	}
	return(0);
}

int main(void)
{
	t_list *lst;
	t_list *list2;
	int a = 3;
	int b = 5;
	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &a;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &b;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = &a;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = &a;
	lst->next->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->next->data = &b;
	lst->next->next->next->next->next =  0;
	list2 = lst->next;
	ft_list_find(lst,&b,cmp);
	while (list2)
	{
		free(lst);
		lst = list2;
		list2 = list2->next;
	}
	free(lst);
	return (0);
}
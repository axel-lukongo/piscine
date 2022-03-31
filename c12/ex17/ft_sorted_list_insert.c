#include<stdlib.h>
#include"ft_list.h"
/*
int cmp(void *data, void *data_ref)
{

	int *i = data;
	int *j = data_ref;
	if (*i > *j)
	{
		return (1);
	}
	return (-1);
}
*/
void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *lst;
	lst = *begin_list1;
	while (lst->next)
	{
		lst = lst->next;
	}
	lst->next = begin_list2;
}

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *current;
	void *next_list;
	current = *begin_list;
	while (current->next)
	{
		if ((*cmp)(current->data, current->next->data) > 0)
		{
			next_list = current->data;
			current->data = current->next->data;
			current->next->data = next_list;
			current = *begin_list; 
		}
		else
			current = current->next;
	}
}
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1,begin_list2);
	ft_list_sort(begin_list1,cmp);
}
/*
int main(void)
{
	t_list *lst;
	t_list *list2;
	t_list *ptr1;
	int i = 3;
	int r = 4;
	int j = 2;
	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &i;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &i;
	lst->next->next =  NULL;

	list2 = (t_list*)malloc(sizeof(t_list));
	list2->data = &r;
	list2->next = (t_list*)malloc(sizeof(t_list));
	list2->next->data = &j;
	list2->next->next =  NULL;
	ft_sorted_list_merge(&lst,list2,cmp);	
	print_list(lst);
	ptr1 = lst->next;
	while (ptr1)
	{
		free(lst);
		lst = ptr1;
		ptr1 = ptr1->next;
	}
	free(lst);
	return (0);
}*/
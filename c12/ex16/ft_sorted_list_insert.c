#include"ft_list.h"
#include<stdlib.h>

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

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_back(begin_list,data);
	ft_list_sort(begin_list, cmp);
}

int main(void)
{
	t_list *lst;
	t_list *list2;
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 6;
	int ajt = 3;
	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &d;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &b;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = &a;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = &e;
	lst->next->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->next->data = &c;
	lst->next->next->next->next->next =  NULL;
	print_list(lst);
	ft_sorted_list_insert(&lst, &ajt,cmp);
	print_list(lst);
	list2 = lst->next;
	while (list2)
	{
		free(lst);
		lst = list2;
		list2 = list2->next;
	}
	free(lst);
	return (0);
}
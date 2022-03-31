#include"ft_list.h"
#include<stdlib.h>

int ft_list_size(t_list *begin_list)
{
	int count;
	count = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		count++;
	}
	return(count);
}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;
	i = 0;
	if (!begin_list)
	{
		return(0);
	}
	int *t;	
	while (i < nbr && begin_list)
	{
		t = begin_list->data;
		begin_list = begin_list->next;
		i++;
	}
	(void)t;
	return(begin_list);
}

void ft_list_reverse_fun(t_list *begin_list)
{
	int i;
	int j;
	int *t;
	int *r;
	(void)r;
	(void)t;
	t_list *last_list;
	void *last_elem;
	i = 0;
	j = ft_list_size(begin_list);

	if (!begin_list || !begin_list->next)
		return;
	while (i < j)
	{
		j--;
		last_list = ft_list_at(begin_list,j-i);
		last_elem = last_list->data;
		t = last_elem;
		r = begin_list->data;
		last_list->data = begin_list->data;
		begin_list->data = last_elem;
		i++;
		begin_list = begin_list->next;
	}
	

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
	list2 = lst->next;
	print_list(lst);
	ft_list_reverse_fun(lst);
	print_list(lst);
	while (list2)
	{
		free(lst);
		lst = list2;
		list2 = list2->next;
	}
	free(lst);
	return (0);
}
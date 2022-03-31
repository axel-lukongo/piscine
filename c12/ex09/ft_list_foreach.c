#include"ft_list.h"
#include<stdio.h>
#include<stdlib.h>
void f(void *data)
{
	(void) data;
	printf("good\n");
}

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

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{	
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}		
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
	//print_list(lst);
	ft_list_foreach(lst,f);
	//print_list(lst);
	while (list2)
	{
		free(lst);
		lst = list2;
		list2 = list2->next;
	}
	free(lst);
	return (0);
}
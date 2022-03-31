#include"ft_list.h"
#include<stdlib.h>
void free_fct(void *data)
{
	(void)data;
}
void ft_list_clear(t_list *begin_list)//,void(*free_fct)(void*))
{
	t_list *next_list;
	while (begin_list->next)
	{
		//free_fct(begin_list->data);
		next_list = begin_list->next;
		free(begin_list);
		begin_list = next_list;
	}
}

int main(void)
{
	t_list *lst;
	t_list *list2;
	int i = 3;
	int j = 1;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &i;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &i;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = &i;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = &j;
	lst->next->next->next->next =  NULL;
	print_list(lst);	
	ft_list_clear(lst);
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
	free(lst);
	return (0);
}
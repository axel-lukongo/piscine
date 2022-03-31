#include"ft_list.h"
#include<stdlib.h>
#include<stdio.h>

void free_fct(void *data)
{
	(void)data;
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

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list *current;
	t_list *next_list;
	(void)free_fct;
		while((*cmp)((*begin_list)->data,data_ref) == 0)
		{
			current = (*begin_list)->next;
			//(*free_fct)(current->data);
			free(*begin_list);
			*begin_list = current;
		}
	current = *begin_list;
	while (current->next)
	{
		next_list = current->next;
		if((cmp)(next_list->data,data_ref) == 0)
		{
			current->next = next_list->next;
			//free(next_list->data);
			free(next_list);
			next_list = current->next;
		}
		else
			current = current->next;
	}
}

int main(void)
{
	t_list *lst;
	t_list *list2;
	int i = 3;
	int j = 0;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &i;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &j;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = &i;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = &j;
	lst->next->next->next->next =  NULL;
	ft_list_remove_if(&lst, &j, cmp, free_fct);
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
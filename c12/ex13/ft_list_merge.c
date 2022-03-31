#include "ft_list.h"
#include<stdlib.h>

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

int main(void)
{
	t_list *lst;
	t_list *list2;
	t_list *ptr1;
	int i = 3;
	int j = 2;
	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &i;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &i;
	lst->next->next =  NULL;

	list2 = (t_list*)malloc(sizeof(t_list));
	list2->data = &j;
	list2->next = (t_list*)malloc(sizeof(t_list));
	list2->next->data = &j;
	list2->next->next =  NULL;
	
	ft_list_merge(&lst, list2);
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
}
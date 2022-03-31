#include "ft_list.h"
#include <stdlib.h>
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
#include<stdio.h>
int main()
{
	t_list *tes;
	t_list *b;
	tes = ft_create_elem("2");
	ft_list_push_front(&tes,"4");
	printf("ils y'a %d malloin\n",ft_list_size(tes));
	while (tes->next)
	{
		b = tes->next;
		free(tes);
		tes = b;
	}
	free(tes);
	
}
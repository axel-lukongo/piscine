#include"ft_list.h"
#include<stdlib.h>

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *li;

	if(!(begin_list))
		 *begin_list = ft_create_elem(data);

	else
		{
			li = ft_create_elem(data);
			li->next = *begin_list;
			*begin_list = li;
		}
		
}


#include<stdio.h>

void print_list(t_list *beta)
{
	char c;
	while (beta != NULL)
	{
		c = *((char*)beta->data);
		printf("[%c]--->", c);
		beta = beta->next;
	}
	
}

int main()
{
	t_list *test;
	t_list *lst;
	test = ft_create_elem("1");
	ft_list_push_front(&test,"3");
	print_list(test);
	while (test->next)
	{
		lst = test->next;
		free(test);
		test = lst;
	}
	
	free(test);
	return (0);
}
#include"ft_list.h"
#include<stdlib.h>
t_list *ft_list_push_strs(int size,char **strs)
{
	t_list *element;
	t_list *last_element;
	int i;
	i = 0;
	last_element = 0;
	while (i < size)
	{
		element = ft_create_elem(strs[i]);
		element->next = last_element;
		last_element = element;
		i++;
	}
	return(element);
}
#include<stdio.h>
void print_list(t_list *beta)
{
	char *c;
	while (beta)
	{
		c = ((char *)beta->data);
		printf("[%s]--->", c);
		beta = beta->next;
	}
	printf("NULL");
	printf("\n");
}
int main(int argc, char **argv)
{
	t_list *tes;
	t_list *tes2;
	tes = ft_list_push_strs(argc,argv);
	print_list(tes);
	while (tes->next)
	{
		tes2 = tes->next;
		free(tes);
		tes = tes2;
	}
	free(tes);
	
}
#include "ft_list.h"
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
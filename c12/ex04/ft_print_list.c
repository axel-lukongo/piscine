#include "ft_list.h"
#include<stdio.h>

void print_list(t_list *beta)
{
	char *c;
	while (beta)
	{
		c = beta->data;
		//c = ((char *)beta->data);
		printf("[%c]--->", *c);
		beta = beta->next;
	}
	printf("null");
	printf("\n");
}
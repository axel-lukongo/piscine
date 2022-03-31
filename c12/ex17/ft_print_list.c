#include "ft_list.h"
#include<stdio.h>

void print_list(t_list *beta)
{
	int *c;
	while (beta)
	{
		c = beta->data;
		//c = ((char *)beta->data);
		printf("[%d]--->", *c);
		beta = beta->next;
	}
	printf("%d",*c);
	printf("\n");
}
#include"ft_list.h"
t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;
	i = 0;
	if (!begin_list)
	{
		return(0);
	}
	
	while (i < nbr && begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return(begin_list);
}
#include<stdio.h>
void print_list(t_list *beta)
{
	char c;
	while (beta)
	{
		c = *((char*)beta->data);
		printf("[%c]--->\n", c);
		beta = beta->next;
	}
}

int main(int argc,char **argv)
{
	(void)argc;
	t_list *b;
	t_list *c;
	b = ft_list_push_strs(4,argv);
	c = ft_list_at(b,1);
	print_list(c);
}
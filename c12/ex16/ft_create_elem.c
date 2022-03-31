#include"ft_list.h"
#include<stdlib.h>
#include<stdio.h>

t_list *ft_create_elem(void *data)
{
	t_list *pwd;
	if(!(pwd = malloc(sizeof(t_list))))
		return(0);
	pwd -> next = NULL;
	pwd -> data = data;
	//printf("%s\n",pwd ->data);
	return(pwd);
}
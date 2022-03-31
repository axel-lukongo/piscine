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
int main()
{
	t_list *ptr;
	ptr = NULL;
	ptr = ft_create_elem("3");
	char tes = *((char *)ptr -> data);
	printf("tes = %c\n", tes);
}
#include"ft_list.h"

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
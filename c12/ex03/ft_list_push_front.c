#include"ft_list.h"
#include<stdlib.h>

t_list *ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *li;
	if(!(begin_list))
		 *begin_list = ft_create_elem(data);

	else
		{
			li = ft_create_elem(data);
			//*begin_list = ft_create_elem(data);
			li ->next = *begin_list;
			*begin_list = li;
		}
		return(li);
}
#include "lem_in.h"

void	add_tube(t_tube **tube, char *str)
{
	t_tube *tmp;
	t_tube *list;

	tmp = NULL;
	if ((tmp = (t_tube*)malloc(sizeof(t_tube))))
	{
        tmp->name = ft_strdup(str);
		tmp->next = NULL;
        if (!*tube)
			*tube = tmp;
		else
		{
			list = *tube;
			while (list->next)
				list = list->next;
			list->next = tmp;
		}
	}
	return ;
}

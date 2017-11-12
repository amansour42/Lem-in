
#include "lem_in.h"

static void	delete_room_end(t_room **r)
{
	t_room *tmp;
	t_room *ptmp;

	if (*r)
	{
		if (!((*r)->next))
		{
            free((*r)->name);
			free(*r);
			*r = NULL;
		}
		else
		{
			tmp = *r;
			while ((tmp->next)->next)
				tmp = tmp->next;
			ptmp = tmp->next;
			tmp->next = NULL;
			free(ptmp->name);
            free(ptmp);
		}
	}
	return ;
}

void	delete_room(t_room **r)
{
	while (*r)
		delete_room_end(r);
	*r = NULL;
	return ;
}


#include "lem_in.h"

static void	delete_tube_end(t_tube **t)
{
	t_tube *tmp;
	t_tube *ptmp;

	if (*t)
	{
		if (!((*t)->next))
		{
            free((*t)->name);
			free(*t);
			*t = NULL;
		}
		else
		{
			tmp = *t;
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

static void	delete_tube(t_tube **t)
{
	while (*t)
		delete_tube_end(t);
	*t = NULL;
	return ;
}

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
            delete_tube(&((*r)->tube));
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
            delete_tube(&((*r)->tube));
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

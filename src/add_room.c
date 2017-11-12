#include "lem_in.h"

static void	add_room(t_env *e, int x, int y, char *str)
{
	t_room *tmp;
	t_room *list;

	tmp = NULL;
	if ((tmp = (t_room*)malloc(sizeof(t_room))))
	{
		tmp->x = x;
        tmp->y = y;
        tmp->name = ft_strdup(str);
		tmp->next = NULL;
		tmp->start = (RNBR == 1) ? 1 : 0;
        tmp->end = (e->end) ? 0 : 1;
        if (!R)
			R = tmp;
		else
		{
			list = R;
			while (list->next)
				list = list->next;
			list->next = tmp;
		}
	}
	return ;
}

static  int length(char **str)
{
    int i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}

static void    clean_split(char **s)
{
    int    nbr;

    nbr = length(s);
    while (--nbr >= 0)
    {
        free(*(s + nbr));
        *(s + nbr) = NULL;
    }
    return ;
    free(s);
}

static void treat_error(t_env *e, char **s)
{
    delete_room(&R);
    clean_split(s);
    ft_error(WRONGROOM);
}

void        fill_room(t_env *e, char *str)
{
    char    **s;
    int     x;
    int     y;

    s = ft_strsplit(str, ' ');
    if (length(s) != 3)
        treat_error(e, s);
    if ((x = ft_atoi(s[1]) == -1 && ft_strcmp(s[1], "-1")) ||
            ((y = ft_atoi(s[1]) == -1 && ft_strcmp(s[2], "-1"))))
        treat_error(e, s);
    add_room(e, x, y, s[0]);
    clean_split(s);
}

#include "lem_in.h"

int     check_nbr_ants(t_env *e, char *line)
{
    if ((A = ft_atoi(line) <= 0))
        ft_error(ANTNBR);
    return (1);
}

int     check_room(t_env *e, char *line)
{
    if (!RNBR && ft_strcmp(line, "##start"))
        ft_error(NOSTART);
    else if (!RNBR && !ft_strcmp(line, "##start"))
    {
        RNBR += 1;
        return (1);
    }
    else if (line[0] == '#' && line[1] != '#')
        return (1);
    else if (!ft_strcmp(line, "##end"))
         return (0);
    fill_room(e, line);
    RNBR += 1;
    return (1);
}

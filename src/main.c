#include "lem_in.h"

int main(void)
{
    t_env   e;
    int     error;
    char    *line;
    
    init_map(&e);
    if (get_next_line(0, &line))
        check_nbr_ants(&e, line);
    else
        ft_error(INVALIDMAP);
    free(line);
    while ((get_next_line(0, &line)) && (e.end = check_map(&e, line)))
        free(line);
    if (e.end)
    {
        delete_room(&(e.r));
        ft_error(NOEND);
    }
    fill_room(&e, line);
    free(line);
    check_tubes(&e);
    return (0);
}

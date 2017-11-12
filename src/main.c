#include "lem_in.h"

int main(void)
{
    t_env   e;
    char    *line;
    
    init_map(&e);
    (get_next_line(0, &line)) ? check_nbr_ants(&e, line) : ft_error(INVALIDMAP);
    free(line);
    while ((get_next_line(0, &line)) && (e.end = check_start_end(&e, line)))
        free(line);
    if (e.end)
    {
        delete_room(&(e.r));
        ft_error(NOEND);
    }
    while (get_next_line(0, &line) && !(belong(line, '-')))
    {
        fill_room(&e, line);
        free(line);
    }
    if (!line)
    {
        delete_room(&(e.r));
        ft_error(NOTUBES);
    }
    check_tubes(&e, line);
    print_ants(&e);
    return (0);
}

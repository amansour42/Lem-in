#include "lem_in.h"

void    print_ants(t_env *e)
{
    t_room *r;
    t_tube *t;
    
    printf("NBR OF ANTS = %d\n", A);
    r = R;
    while (r)
    {
        printf("ROOM = %s, x = %d, y = %d\n", r->name, r->x, r->y);
        t = r->tube;
        printf("TUBES\n");
        while (t)
        {
            printf("%s-%s\n", r->name, t->name);
            t = t->next;
        }
        r = r->next;
    }
}



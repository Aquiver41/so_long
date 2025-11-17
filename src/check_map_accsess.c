#include "so_long.h"
char **clone_map(t_vars *vars)
{
    char **clone;

    int i;
    i = 0;
    clone = malloc(sizeof(char *) * (vars->map->m_height + 1));
    if (!clone)
        exit_aticam("Couldn't creat clone map", vars);
    while(i < vars->map->m_height)
    {
        clone[i] = ft_strdup(vars->map->map[i]);
        if (!clone[i])
            exit_aticam("oluşmadı",vars);
    i++;
    }
    clone[i] = NULL;
    return(clone);
}

void check_map_acsess(t_vars *vars)
{
    clone_map(vars);
    flood_fill();
}
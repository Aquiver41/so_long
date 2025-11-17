#include "so_long.h"
#include <stdlib.h>
#include "ft_printf.h"

void ft_error(char *av)
{
    ft_printf("%s\n", av);
    exit (0);
}

void ft_exit(char *str, t_vars *vars)
{
    free(vars->map);
    free(vars);
    ft_printf("%s\n", str);
}
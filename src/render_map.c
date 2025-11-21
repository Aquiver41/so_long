#include "so_long.h"
#include "mlx.h"

void render_map(t_vars *vars)
{
    int     y;
    int     x;
    char    c;

    y = 0;
    while (y < vars->map->m_height)
    {
        x = 0;
        while(x < vars->map->m_width)
        {
            c = vars->map->map[y][x];
            if (c == '1')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall, x * 48, y * 48);
            else
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor, x * 48, y * 48);
            if (c == 'E')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit, x * 48, y * 48);   
            else if (c == 'C')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img.colletibiles, x * 48, y * 48);
            x++;
        }
        y++;
    }
}

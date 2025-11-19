#include "so_long.h"
#include "mlx.h"

void render_map(t_vars *vars)
{
    int y;
    int x;

    y = 0;
    while (y < vars->map->m_height)
    {
        x = 0;
        while(x < vars->map->m_width)
        {
        char c = vars->map->map[y][x];
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor, x * 96, y * 96);
        if (c == '1')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall, 
                x * 96, y * 96);
        else if (c == 'C')
            mlx_put_image_to_window(vars->mlx, vars->win,vars->img.colletibiles,
                x * 96, y * 96);   
        else if (c == 'E')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit, 
                x * 96, y * 96);
        else if (c == 'P')
            mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, 
                x * 96, y * 96);
        x++;
        }
    y++;
    }
}
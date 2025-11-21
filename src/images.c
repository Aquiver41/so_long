#include "so_long.h"
#include "mlx.h"
#include <stdio.h>

int images(t_vars *vars)
{
    vars->img.wall = mlx_xpm_file_to_image(vars->mlx, "img/wall.xpm" , &vars->img.img_h, &vars->img.img_w);
    vars->img.player = mlx_xpm_file_to_image(vars->mlx, "img/player.xpm" , &vars->img.img_h, &vars->img.img_w);
    vars->img.floor = mlx_xpm_file_to_image(vars->mlx, "img/floor.xpm" , &vars->img.img_h, &vars->img.img_w);
    vars->img.exit = mlx_xpm_file_to_image(vars->mlx, "img/exit.xpm" , &vars->img.img_h, &vars->img.img_w);
    vars->img.colletibiles = mlx_xpm_file_to_image(vars->mlx, "img/coin.xpm" , &vars->img.img_h, &vars->img.img_w);
    if (!vars->img.wall || !vars->img.floor || !vars->img.player || !vars->img.exit || !vars->img.colletibiles)
		  return (1);
	  return (0);
}
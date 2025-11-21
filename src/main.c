#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	exit_aticam(char *message, t_vars *vars)
{
	int	i;

	i = 0;
	if (vars)
	{
		while (vars->map->map[i])
		{
			free(vars->map->map[i]);
			i++;
		}
		free(vars->map->map);
		free(vars->map);
		free(vars);
	}
	ft_printf("%s\n", message);
	exit(1);
}

void move(int keycode , t_vars *vars)
{
	if ((keycode == 119 || keycode == 65362) && vars->map->map[vars->p_height - 1][vars->p_width] != '1')
        vars->p_height--;
	else if ((keycode == 97 || keycode == 65364) && vars->map->map[vars->p_height][vars->p_width - 1] != '1')
        vars->p_width--;
	else if ((keycode == 100 || keycode == 65361) && vars->map->map[vars->p_height][vars->p_width + 1] != '1')
        vars->p_width++;
	else if ((keycode == 115 || keycode == 65363) && vars->map->map[vars->p_height + 1][vars->p_width] != '1')
        vars->p_height++;
	else
		return ;
	ft_printf("Moves: %d\n", ++vars->movement);
	if (vars->map->map[vars->p_height][vars->p_width] == 'C')
	{
		vars->c_c--;
		vars->map->map[vars->p_height][vars->p_width] = '0';
	}
	if (vars->map->map[vars->p_height][vars->p_width] == 'E' && vars->c_c == 0)
	{
		ft_printf("Sancar Win!\n");
		close_win(vars);
	}
}

int	key_press(int key, t_vars *vars)
{
	if (key == 65307)
		close_win(vars);
	if (key == 119 || key == 115 || key == 97 || key == 100
        || key == 65362 || key == 65364 || key == 65361 || key == 65363)
        	move(key, vars);
	return (0);
}

int	close_win(t_vars *vars)
{
	if (vars)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.wall);
		mlx_destroy_image(vars->mlx, vars->img.player);
		mlx_destroy_image(vars->mlx, vars->img.floor);
		mlx_destroy_image(vars->mlx, vars->img.exit);
		mlx_destroy_image(vars->mlx, vars->img.colletibiles);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit_aticam("EXIT!", vars);
	exit(1);
}

int	init_mlx(t_vars *vars)
{
	int win_w;
	int win_h;
	
	win_h = vars->map->m_height * 48;
	win_w = vars->map->m_width * 48;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		return 1;
	vars->win = mlx_new_window(vars->mlx, win_w, win_h ,"so_long");
	if (images(vars)) // başarılıysa 0 döner ve girmez zaten;
		exit_aticam("fotolar gitti!", vars);
	return (0);
}

int new_mlx(t_vars *vars)
{
	render_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, vars->p_width
		* 48, vars->p_height * 48);
	return (0);
}

int	main(int ac, char **av)
{
    t_vars * vars;

	if (ac != 2)
		exit_aticam("Check number of arguments!", NULL);
	check_av(av[1]);
	vars_init(av[1], &vars);
	check_map_acces(vars);
	if (init_mlx(vars))
	{
		free(vars->map);
		free(vars);
		return 1;
	}
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	//	mlx_key_hook(vars->win, key_press, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_loop_hook(vars->mlx, new_mlx , vars);
	mlx_loop(vars->mlx);
}

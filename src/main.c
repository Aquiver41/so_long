#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	exit_aticam(char *message, t_vars *vars)
{
	if (vars)
	{
		free(vars->map->map);
		free(vars->map);
		free(vars);
	}
	ft_printf("%s\n", message);
	exit(1);
}

void move(int keycode , t_vars *vars)
{
	if (keycode == 119 || keycode == 65362)
        vars->p_height--;
	if (keycode == 115 || keycode == 65364)
        vars->p_height++;
	if (keycode == 97 || keycode == 65361)
        vars->p_width--;
	if (keycode == 100 || keycode == 65363)
        vars->p_width++;
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
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free(vars->map);
	free(vars);
	exit(1);
}

int	init_mlx(t_vars *vars)
{
	int win_w;
	int win_h;
	
	win_h = vars->map->m_height * 96;
	win_w = vars->map->m_width * 96;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		return 1;
	vars->win = mlx_new_window(vars->mlx, win_w, win_h ,"so_long");
	if (images(vars)) // başarılıysa 0 döner ve girmez zaten;
		exit_aticam("fotolar gitti!", vars);
	render_map(vars);
	return (0);
}

/* int new_mlx(t_vars *vars)
{
	render_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, NULL, vars->p_width
		* 96, vars->p_height * 96);
	return (0);
} */

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
	mlx_key_hook(vars->win, key_press, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	//mlx_loop_hook(vars->mlx, new_mlx , vars);
	mlx_loop(vars->mlx);
}

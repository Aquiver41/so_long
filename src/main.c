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

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
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
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_loop(vars->mlx);
}

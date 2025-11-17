#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

# define TILE 32
# define BUFFER_SIZE 42

typedef struct s_map
{
	char **map;
	int  width; // sütun
	int height; // satır
	int exit;  // exit
	int player; // player start position
	int wall; // wall
	int m_height; // map height
	int m_width;  // map width
	int p_height; // player height
	int p_width;  // player width
}	t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_map	*map;
	int temp_c;
	int temp_e;
	int collectibles;
	int m_width;  // map width
	int p_height; // player height
	int p_width;
	int movement;
}	t_vars;

int close_win(t_vars *vars);
void check_av(const char *map);
void ft_error(char *av);
void	vars_init(const char *map, t_vars **vars);
void	exit_aticam(char *message, t_vars *vars);
void	m_scaling(t_vars **vars);
void	p_scaling(t_vars **vars);
int index_counter(t_vars *vars, char c);
char	*get_next_line(int fd);
int read_file_map(char *map);
char **clone_map(t_vars *vars);
#endif

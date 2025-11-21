#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

void	check_av(const char *map)
{
	int len;
    int fd;
	len = 0;

	if (!map)
		exit_aticam("Map yok ula!", NULL);
	while (map[len])
		len++;
	if (len < 4)
		exit_aticam("Map uzantın hatalı sanırsam!",NULL);
	if (!(map[len - 1] == 'r' && map[len - 2] == 'e' &&
		map[len - 3] == 'b' && map[len - 4] == '.'))
		exit_aticam("Your file extension is wrong! Usage : <.ber>", NULL);
    fd = open(map, O_RDONLY);
    if (fd < 0)
        exit_aticam("Dosyanı açamadım uşak!",NULL);
    close (fd);
}

int	index_counter(t_vars *vars, char c)
{
	int i;
	int j;
	int i_counter;
	
	i_counter = 0;
	i = 0;
	while (vars->map->map[i])
	{
		j = 0;
		while(vars->map->map[i][j])
		{
			if (vars->map->map[i][j] == c)
				i_counter++;
			j++;
		}
		i++;
	}
	return i_counter;
}

int read_file_map(char *map)
{
    int i;
    int fd;
    char *line;

    i = 0;
    fd = open(map, O_RDONLY);
    if (fd < 0)
        return(0);
    while(1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        i++;
        free(line);
    }
    close(fd);
    return(i);

}
#include <stdio.h>

void	m_scaling(t_vars **vars)
{
	int	i;

	i = 0;
	while ((*vars)->map->map[i])
		i++;
	(*vars)->map->m_height = i;
	(*vars)->map->m_width = ft_strlen((*vars)->map->map[0]);
}

void	p_scaling(t_vars **vars)
{
	int	i;
	int	j;

	i = 0; 
	while ((*vars)->map->map[i])
	{
		j = 0;
		while ((*vars)->map->map[i][j])
		{
			if ((*vars)->map->map[i][j] == 'P')
			{
				(*vars)->p_height = i;
				(*vars)->p_width= j;
				return ;
			}
			j++;
		}
		i++;
	}
	exit_aticam("Player not found\n", (*vars));
}

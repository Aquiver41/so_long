#include "so_long.h"
#include  "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

static void map_height(const char *map, int *height, t_vars *vars)
{
    int     fd;
    int     check;
    char    c;

    fd = open(map, O_RDONLY);
    if (fd < 0)
        exit_aticam("File can not open!", vars);
    check = 1;
    while (check > 0)
    {
        check = read(fd, &c, 1);
        if (check < 0)
            break;
        if (c == '\n')
            (*height)++; // *height++; idi
    }
    close(fd);
}

static void aralarda_nl_varmı(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (vars->map->map[i][j] && vars->map->map[i][j] != '\n')
    {
        j++;
    }
    if (vars->map->map[i][j] == '\n')
    {
        i++;
        if (vars->map->map[i][0] == '\n')
            exit_aticam("böyle map mi olur", vars);
    }
}

#include <stdio.h>

static void genel_kontrol(t_vars *vars)
{
    unsigned int genislik;
    int i;
    int j;

    i = 1;
    j = 0;
    genislik = ft_strlen(vars->map->map[0]);
    while (vars->map->map[0][j])
    {
        if (vars->map->map[0][j] != '1')
            exit_aticam("Map not surrended by walls!", vars);
        j++;
    }
    while (vars->map->map[i])
    {
        if (ft_strlen(vars->map->map[i]) != genislik)
            exit_aticam("Map not rectangular!", vars);
        if (vars->map->map[i][0] != '1' || vars->map->map[i][genislik - 1] != '1')
            exit_aticam("Map not surrended by walls!", vars);
        j = 0;
        while (vars->map->map[i][j])
        {
            if (vars->map->map[i][j] != '1' && vars->map->map[i][j] != '0'
                && vars->map->map[i][j] != 'P' && vars->map->map[i][j] != 'E'
                && vars->map->map[i][j] != 'C')
            {
                exit_aticam("sadgsdıgjwsp",vars);
            }
            j++;
        }
        i++;
    }

    if (index_counter(vars, 'P') != 1 || index_counter(vars, 'E') != 1)
        exit_aticam("Error\nMap must contain exactly 1 Player and 1 Exit\n", vars);

    j = 0;
    while (vars->map->map[i - 1][j])
    {
        if (vars->map->map[i - 1][j] != '1')
            exit_aticam("Map not surrended by walls!", vars);
        j++;
    }
}

static void mapi_check_ediyoruz(t_vars *vars)
{
    aralarda_nl_varmı(vars);
    // nlları_sil(vars);
    genel_kontrol(vars);
}

static void load_map(const char *map, t_vars *vars, int height)
{
    int fd;
    int i;
    char    *line;

    fd = open(map, O_RDONLY);
    if (fd < 0)
        exit_aticam("File can not open!", vars);
    vars->map->map = malloc(sizeof(char *) * (height + 2));
    if (!vars->map->map)
    {
        close(fd);
        exit_aticam("Malloc allocation failed!", vars);
    }
    i = 0;
    line = get_next_line(fd);
    // printf("*%s*\n", line);
    while (line)
    {
        vars->map->map[i] = line; // strdup hatalı olabilir bak.
        i++;
        line = get_next_line(fd);
        // printf("*%s*\n", line);
    }
    vars->map->map[i] = NULL;
    // for (int j = 0; vars->map->map[j]; j++)
    //     printf("<%s>\n",  vars->map->map[j]);
    close(fd);
    mapi_check_ediyoruz(vars);
}

void    vars_init(const char *map, t_vars **vars)
{
    int height;

    height = 0;
    (*vars) = ft_calloc(1, sizeof(t_vars));
    if (!*vars)
        exit_aticam("Malloc allocation failed!", NULL);
    (*vars)->map = ft_calloc(1, sizeof(t_map));
    if (!(*vars)->map)
        exit_aticam("Malloc allocation failed!", (*vars));
    map_height(map, &height, (*vars));
    (*vars)->map->height = height; 
    load_map(map, (*vars), height);
    if (!(*vars)->map || !(*vars)->map->map) // sonra tekrar kontrol et
        exit_aticam("map yükleme hatası!", *vars);
    (*vars)->c_c = index_counter((*vars), 'C'); // bak 
    if (!vars)
        exit_aticam("coin yok aq!", *vars);
    (*vars)->temp_c = (*vars)->collectibles;
	(*vars)->temp_e = 1;
    
    m_scaling(vars); // 6 lık haritanın heigth ini eksik alıyor.
    p_scaling(vars); // hatam yok gibi
    (*vars)->movement = 0;
}

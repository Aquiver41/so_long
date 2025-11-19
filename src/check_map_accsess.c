#include "so_long.h"
#include "../libft/libft.h"

#include <stdio.h>

char **clone_map(t_vars *vars)
{
    char **clone;

    int i;
    i = 0;
    clone = malloc(sizeof(char *) * (vars->map->m_height + 1));
    if (!clone)
        exit_aticam("Couldn't creat clone map", vars);
    while(i < vars->map->m_height)
    {
        clone[i] = ft_strdup(vars->map->map[i]);
        if (!clone[i])
            exit_aticam("oluşmadı",vars);
    i++;
    }
    clone[i] = NULL;
    
    return(clone);
}

void flood_fill(char **clone, int y, int x, t_vars *vars) // oyuncunun satırı y, oyuncunun konumunun sütunu x, yani flood fill bu konumdan itibaren yayılmaya başlıcak.
{
  /*   printf("FF ENTER: y=%d x=%d char=%c\n", y, x, clone[y] ? clone[y][x] : '?'); */

    int w;

    if (y < 0 || y >= vars->map->m_height) // satır sınırı 0 <= y < m_heght
        return;
    w = (int)ft_strlen(clone[y]); // clone mapimin o satırının uzunluğunu al yani y. satırın kaç w  i var
    if (x < 0 || x >= w) // çok sola gittin veya satrıın sonundan çıktın gittin
        return;
    if (clone[y][x] == '1' || clone[y][x] == 'L') // duvarsa veya kontrol edildiyse dur bcs duvardan geçemez
        return;
    clone[y][x] = 'L'; // looked
    flood_fill(clone, y + 1, x, vars); // aşağı
    flood_fill(clone, y - 1, x, vars); // yukarı
    flood_fill(clone, y, x + 1, vars); // sağ
    flood_fill(clone, y, x - 1, vars); // sol
}

void check_clone_acsess(char **clone ,t_vars *vars) // her yere gidebiliyorsa oyuncu içinde c ve e kalmamalı burad onun kontrolünü yapacğım. vars hatalı maptir exitatıcam
{
    int y;
    int x;

    y = 0;
    while(clone[y])
    {
        x = 0;
        while (clone[y][x])
        {
            if (clone[y][x] == 'C' || clone[y][x] == 'E')
                exit_aticam("The map is not suitable!", vars);
            x++;
        }
        y++;    
    }
}

void free_clone_map(char **clone, int h)
{
    int i;

    i = 0;
    while (i < h)
    {
        free(clone[i]);
        i++;
    }
    free(clone);
}

void check_map_acces(t_vars *vars)
{
    char **clone;
    clone = clone_map(vars); // kopya oluştur
    flood_fill(clone, vars->p_height, vars->p_width,vars); // clone mapte oyuncunun gidebildiği yerleri işaretle
    /*        printf("CLONE AFTER FLOOD:\n");
    int i = 0;
    while (clone[i])
    {
        printf("%s\n", clone[i]);
        i++;
    } */
    check_clone_acsess(clone, vars); // oyuncu gidebiliypr mu bak gidemiyorsa exit at
    free_clone_map(clone, vars->map->m_height); // bütün clone mapin satırlarını freele
}
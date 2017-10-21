#ifndef BATTLE_H

# define BATTLE_H

# include "libft.h"

typedef struct  s_boat
{
        char    slot[7];
        int     x[7];
        int     y[7];
}               t_boat;

typedef struct  s_data
{
        char    player_map[11][11];
        t_boat  *player_small_boat;
}               t_data;

int   placement_player_boats(t_data *info, int size);
int   checker(t_data *info, int size, int dir, char coord[4]);

#endif

#ifndef BATTLE_H

# define BATTLE_H

# include <time.h>
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
        char    ia_map[11][11];
        t_boat  *player_small_boat;
        t_boat  *player_boat;
        t_boat  *player_submarine;
        t_boat  *player_cruiser;
        t_boat  *player_aircraft;
        t_boat  *ia_small_boat;
        t_boat  *ia_boat;
        t_boat  *ia_submarine;
        t_boat  *ia_cruiser;
        t_boat  *ia_aircraft;
}               t_data;

int   ia_checker(t_data *info, int size, int dir, char coord[4]);
void  print_map(char map[11][11]);
void  put_boats(t_data *info);
int   placement_ia_boats(t_data *info, int size);
int   placement_player_boats(t_data *info, int size);
int   checker(t_data *info, int size, int dir, char coord[4]);

#endif

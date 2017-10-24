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
        t_boat  *player_spy_ship;
        t_boat  *player_destroyer;
        t_boat  *player_submarine;
        t_boat  *player_cruiser;
        t_boat  *player_aircraft;
        t_boat  *ia_spy_ship;
        t_boat  *ia_destroyer;
        t_boat  *ia_submarine;
        t_boat  *ia_cruiser;
        t_boat  *ia_aircraft;
}               t_data;

int   is_victory(t_data *info);
int   add_ia_cross(t_data *info, int x, int y);
int   add_player_cross(t_data *info, int x, int y);
int   ia_shoot(t_data *info);
int   player_shoot(t_data *info);
void  game(t_data *info);
int   ia_checker(t_data *info, int size, int dir, char coord[4]);
void  print_map(t_data *info, char *id, char map[11][11]);
void  put_boats(t_data *info);
int   placement_ia_boats(t_data *info, int size);
int   placement_player_boats(t_data *info, int size);
int   checker(t_data *info, int size, int dir, char coord[4]);
int   check_spy_ship(t_boat *b, int x, int y);
int   check_destroyer(t_boat *b, int x, int y);
int   check_submarine(t_boat *b, int x, int y);
int   check_cruiser(t_boat *b, int x, int y);
int   check_aircraft(t_boat *b, int x, int y);

#endif

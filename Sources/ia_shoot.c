#include "../Includes/battle.h"

int  ia_shoot(t_data *info)
{
  int   x;
  int   y;
  int   shoot;

  shoot = 0;
  x = (rand() % 10);
  y = (rand() % 10);
  system("clear");
  ft_printf("{bold}{yellow}Tour de l'IA{res}\n");
  sleep(2);
  if (info->player_map[y][x] == 'O')
    shoot = add_player_cross(info, x, y);
  info->player_map[y][x] = 'X';
  print_map(info, "player", info->player_map);
  sleep(2);
  if (shoot)
    return (ia_shoot(info));
  return (1);
}

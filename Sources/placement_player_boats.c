#include "../Includes/battle.h"

static void set_boat(t_data *info, int x, int y, int size)
{
  t_boat      *boat;
  static int  i = 0;

  if (size == 2)
    boat = info->player_spy_ship;
  else if (size == 3)
    boat = info->player_destroyer;
  else if (size == 4)
    boat = info->player_submarine;
  else if (size == 5)
    boat = info->player_cruiser;
  else
    boat = info->player_aircraft;
  if (!boat->slot[0])
    ft_memset(boat->slot, 'O', size);
  boat->x[i] = x;
  boat->y[i] = y;
  i++;
}

static void fill_map(t_data *info, int dir, char coord[4], int size)
{
  int   x;
  int   y;
  int   i;

  i = size;
  x = coord[0] - 65;
  if (!coord[2])
    y = coord[1] - 49;
  else
    y = 9;
  while (i)
  {
    set_boat(info, x, y, size);
    info->player_map[y][x] = 'O';
    if (dir == 1)
      y--;
    else if (dir == 2)
      x++;
    else if (dir == 3)
      y++;
    else
      x--;
    i--;
  }
}

int         placement_player_boats(t_data *info, int size)
{
  char  coord[4];
  int   dir;

  ft_bzero(coord, 4);
  ft_printf("{bold}{green}Entrez les coordonnes de la tete du bateau{res}\n");
  scanf("%s", coord);
  ft_printf("{bold}{green}Choisissez une direction\n");
  ft_printf("{bold}{green}1) Nord\n2) Est\n3) Sud\n4) Ouest\n{res}");
  scanf("%d", &dir);
  if (!checker(info, size, dir, coord))
    return (placement_player_boats(info, size));
  fill_map(info, dir, coord, size);
  return (1);
}

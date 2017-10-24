#include "../Includes/battle.h"

static void set_boat(t_data *info, int x, int y, int size)
{
  t_boat      *boat;
  static int  i = 0;

  if (size == 2)
    boat = info->ia_spy_ship;
  else if (size == 3)
    boat = info->ia_destroyer;
  else if (size == 4)
    boat = info->ia_submarine;
  else if (size == 5)
    boat = info->ia_cruiser;
  else
    boat = info->ia_aircraft;
  if (!boat->slot[0])
  {
    i = 0;
    ft_memset(boat->slot, 'O', size);
  }
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
    info->ia_map[y][x] = 'O';
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

int         placement_ia_boats(t_data *info, int size)
{
  char  coord[4];
  int   dir;

  ft_bzero(coord, 4);
  coord[0] = (rand() % (75 - 65)) + 65;
  coord[1] = (rand() % (58 - 48)) + 48;
  dir = (rand() % 4) + 1;
  if (!ia_checker(info, size, dir, coord))
    return (placement_ia_boats(info, size));
  fill_map(info, dir, coord, size);
  return (1);
}

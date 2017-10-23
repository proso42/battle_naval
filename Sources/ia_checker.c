#include "../Includes/battle.h"

static int  check_coord(char coord[4], int *x, int *y)
{
  if (coord[0] < 'A' || coord[0] > 'J' || coord[1] < '1' || coord[1] > '9' ||
      coord[3] || (coord[2] != '0' && coord[2] != '\0'))
    return (0);
  (*x) = coord[0] - 65;
  if (!coord[2])
    (*y) = coord[1] - 49;
  else
    (*y) = 9;
  return (1);
}

static int  check_dir(int dir, int x, int y, int size)
{
  size--;
  if (dir < 1 || dir > 4)
    return (0);
  if (dir == 1)
    y -= size;
  else if (dir == 2)
    x += size;
  else if (dir == 3)
    y += size;
  else
    x -= size;
  if (x > 9 || x < 0 || y > 9 || y < 0)
    return (0);
  return (1);
}

int         ia_checker(t_data *info, int size, int dir, char coord[4])
{
  int   x = -1;
  int   y = -1;

  if (!check_coord(coord, &x, &y))
    return (0);
  else if (!check_dir(dir, x, y, size))
    return (0);
  while (size)
  {
    if (info->ia_map[y][x] != '_')
      return (0);
    if (dir == 1)
      y--;
    else if (dir == 2)
      x++;
    else if (dir == 3)
      y++;
    else
      x--;
    size--;
  }
  return (1);
}

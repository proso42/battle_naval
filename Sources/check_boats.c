#include "../Includes/battle.h"

int   check_spy_ship(t_boat *b, int x, int y)
{
  int   i;

  i = 0;
  while (i < 2)
  {
    if (b->x[i] == x && b->y[i] == y)
      return (1);
    i++;
  }
  return (0);
}

int   check_destroyer(t_boat *b, int x, int y)
{
  int   i;

  i = 0;
  while (i < 3)
  {
    if (b->x[i] == x && b->y[i] == y)
      return (1);
    i++;
  }
  return (0);
}

int   check_submarine(t_boat *b, int x, int y)
{
  int   i;

  i = 0;
  while (i < 4)
  {
    if (b->x[i] == x && b->y[i] == y)
      return (1);
    i++;
  }
  return (0);
}

int   check_cruiser(t_boat *b, int x, int y)
{
  int   i;

  i = 0;
  while (i < 5)
  {
    if (b->x[i] == x && b->y[i] == y)
      return (1);
    i++;
  }
  return (0);
}

int   check_aircraft(t_boat *b, int x, int y)
{
  int   i;

  i = 0;
  while (i < 6)
  {
    if (b->x[i] == x && b->y[i] == y)
      return (1);
    i++;
  }
  return (0);
}

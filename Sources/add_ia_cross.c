#include "../Includes/battle.h"

static int   check_cible_small_boat(t_data *info, int x, int y)
{
  int   i;

  i = 0;
  while (i < 2)
  {
    if (info->ia_spy_ship->x[i] == x && info->ia_spy_ship->y[i] == y)
    {
      info->ia_spy_ship->slot[i] = 'X';
      ft_printf("{bold}{green}Touche !{res}\n");
      return (1);
    }
    i++;
  }
  i = 0;
  while (i < 3)
  {
    if (info->ia_destroyer->x[i] == x && info->ia_destroyer->y[i] == y)
    {
      info->ia_destroyer->slot[i] = 'X';
      ft_printf("{bold}{green}Touche !{res}\n");
      return (1);
    }
    i++;
  }
  return (0);
}

static int   check_cible_submarine(t_boat *b, int x, int y)
{
  int   i;

  i = 0;
  while (i < 4)
  {
    if (b->x[i] == x && b->y[i] == y)
    {
      b->slot[i] = 'X';
      ft_printf("{bold}{green}Touche !{res}\n");
      return (1);
    }
    i++;
  }
  return (0);
}

static int   check_cible_cruiser(t_boat *b, int x, int y)
{
  int   i;

  i = 0;
  while (i < 5)
  {
    if (b->x[i] == x && b->y[i] == y)
    {
      b->slot[i] = 'X';
      ft_printf("{bold}{green}Touche !{res}\n");
      return (1);
    }
    i++;
  }
  return (0);
}

static int   check_cible_aircraft(t_boat *b, int x, int y)
{
  int   i;

  i = 0;
  while (i < 6)
  {
    if (b->x[i] == x && b->y[i] == y)
    {
      b->slot[i] = 'X';
      ft_printf("{bold}{green}Touche !{res}\n");
      return (1);
    }
    i++;
  }
  return (0);
}

int  add_ia_cross(t_data *info, int x, int y)
{
  if (check_cible_small_boat(info, x, y))
    return (1);
  else if (check_cible_submarine(info->ia_submarine, x, y))
    return (1);
  else if (check_cible_cruiser(info->ia_cruiser, x, y))
    return (1);
  else if (check_cible_aircraft(info->ia_aircraft, x, y))
    return (1);
  else
  {
    ft_printf("{bold}{red}Aucune cible touchee{res}\n");
    return (0);
  }
}

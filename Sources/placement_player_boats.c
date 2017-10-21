#include "../Includes/battle.h"

static void fill_map(t_data *info, int dir, char coord[4], int size)
{
  int   x;
  int   y;

  x = coord[0] - 65;
  if (!coord[2])
    y = coord[1] - 49;
  else
    y = 9;
  while (size)
  {
    info->player_map[y][x] = 'O';
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

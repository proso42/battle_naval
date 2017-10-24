#include "../Includes/battle.h"

static int  print_error(int err)
{
  if (err == 1)
    ft_printf("{bold}{red}Coordonnees invalides !{res}\n");
  else if (err == 2)
    ft_printf("{bold}{red}Vous avez deja tire ici !{res}\n");
  return (0);
}

static int  check_coord(t_data *info, char coord[4], int *x, int *y)
{
  if (coord[0] < 'A' || coord[0] > 'J' || coord[1] < '1' || coord[1] > '9' ||
      coord[3] || (coord[2] != '0' && coord[2] != '\0'))
    return (print_error(1));
  (*x) = coord[0] - 65;
  if (!coord[2])
    (*y) = coord[1] - 49;
  else
    (*y) = 9;
  if (info->ia_map[*y][*x] == 'X')
    return (print_error(2));
  return (1);
}

int  player_shoot(t_data *info)
{
  char  coord[4];
  int   x;
  int   y;
  int   shoot;

  shoot = 0;
  ft_bzero(coord, 4);
  ft_printf("{bold}{yellow}Entrez les coordoonnes de la cible{res}\n");
  print_map(info, "ia", info->ia_map);
  scanf("%s", coord);
  system("clear");
  if (!check_coord(info, coord, &x, &y))
    return (player_shoot(info));
  if (info->ia_map[y][x] == 'O')
    shoot = add_ia_cross(info, x, y);
  info->ia_map[y][x] = 'X';
  if (shoot)
    return (player_shoot(info));
  print_map(info, "ia", info->ia_map);
  sleep(2);
  return (1);
}

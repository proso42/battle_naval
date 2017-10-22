#include "../Includes/battle.h"

static void print_map(char map[11][11])
{
    int   i = 0;
    int   j = 0;

    ft_printf("{bold}{white}   A B C D E F G H I J{res}\n");
    while (i < 10)
    {
      if (i < 9)
        ft_printf("{bold}{white}%d  {res}", i + 1);
      else
        ft_printf("{bold}{white}10 {res}");
      while (j < 10)
      {
        ft_printf("{bold}{cyan}%c {res}", map[i][j]);
        j++;
      }
      j = 0;
      i++;
      write(0, "\n", 1);
    }
}

static char *name_boat(int i)
{
  if (i == 2)
    return ("petit bateau");
  else if (i == 3)
    return ("bateau");
  else if (i == 4)
    return ("sous-marin");
  else if (i == 5)
    return ("croiseur");
  else
    return ("porte-avion");
}

static void init(t_data *info)
{
  int     i = 0;

  ft_bzero(info->player_map, 132);
  while (i < 10)
  {
    ft_memset(info->player_map[i], '_', 10);
    i++;
  }
  i = 2;
  info->player_small_boat = (t_boat*)malloc(sizeof(t_boat));
  info->player_boat = (t_boat*)malloc(sizeof(t_boat));
  info->player_submarine = (t_boat*)malloc(sizeof(t_boat));
  info->player_cruiser = (t_boat*)malloc(sizeof(t_boat));
  info->player_aircraft = (t_boat*)malloc(sizeof(t_boat));
  while (i < 7)
  {
    print_map(info->player_map);
    ft_printf("{bold}{green}Placement du %s{res}\n", name_boat(i));
    placement_player_boats(info, i);
    system("clear");
    i++;
  }
  print_map(info->player_map);
}

int         main()
{
  t_data  info;

  init(&info);
  return 0;
}

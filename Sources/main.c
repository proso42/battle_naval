#include "../Includes/battle.h"

void print_map(char map[11][11])
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

static void init_ia_map(t_data *info)
{
  int   i;

  i = 0;
  while (i < 10)
  {
    ft_memset(info->ia_map[i], '_', 10);
    i++;
  }
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
  ft_bzero(info->ia_map, 132);
  init_ia_map(info);
  info->player_small_boat = (t_boat*)malloc(sizeof(t_boat));
  info->player_boat = (t_boat*)malloc(sizeof(t_boat));
  info->player_submarine = (t_boat*)malloc(sizeof(t_boat));
  info->player_cruiser = (t_boat*)malloc(sizeof(t_boat));
  info->player_aircraft = (t_boat*)malloc(sizeof(t_boat));
  info->ia_small_boat = (t_boat*)malloc(sizeof(t_boat));
  info->ia_boat = (t_boat*)malloc(sizeof(t_boat));
  info->ia_submarine = (t_boat*)malloc(sizeof(t_boat));
  info->ia_cruiser = (t_boat*)malloc(sizeof(t_boat));
  info->ia_aircraft = (t_boat*)malloc(sizeof(t_boat));
  put_boats(info);
}

int         main()
{
  t_data  info;

  srand(time(NULL));
  init(&info);
  system("clear");
  ft_printf("Player Map\n");
  print_map(info.player_map);
  ft_printf("IA Map\n");
  print_map(info.ia_map);
  return 0;
}

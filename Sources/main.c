#include "../Includes/battle.h"

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
  info->player_spy_ship = (t_boat*)malloc(sizeof(t_boat));
  info->player_destroyer = (t_boat*)malloc(sizeof(t_boat));
  info->player_submarine = (t_boat*)malloc(sizeof(t_boat));
  info->player_cruiser = (t_boat*)malloc(sizeof(t_boat));
  info->player_aircraft = (t_boat*)malloc(sizeof(t_boat));
  info->ia_spy_ship = (t_boat*)malloc(sizeof(t_boat));
  info->ia_destroyer = (t_boat*)malloc(sizeof(t_boat));
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
  game(&info);
  return 0;
}

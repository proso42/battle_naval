#include "../Includes/battle.h"

void  game(t_data *info)
{
  int   start;

  start = (rand() % (3)) + 1;
  ft_printf("%d\n", start);
  if (start == 1)
  {
    while (!is_victory(info))
    {
      ft_printf("{bold}{yellow}Tour du joueur{res}\n");
      player_shoot(info);
      ft_printf("{bold}{yellow}Tour de l'IA{res}\n");
      ia_shoot(info);
    }
  }
  else
  {
    while (!is_victory(info))
    {
      ft_printf("{bold}{yellow}Tour de l'IA{res}\n");
      ia_shoot(info);
      ft_printf("{bold}{yellow}Tour du joueur{res}\n");
      player_shoot(info);
    }
  }
}

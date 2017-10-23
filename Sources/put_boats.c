#include "../Includes/battle.h"

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

void  put_boats(t_data *info)
{
  int i;

  i = 2;
  while (i < 7)
  {
    print_map(info->player_map);
    ft_printf("{bold}{green}Placement du %s{res}\n", name_boat(i));
    placement_player_boats(info, i);
    system("clear");
    i++;
  }
  i = 2;
  while (i < 7)
  {
    placement_ia_boats(info, i);
    i++;
  }
}

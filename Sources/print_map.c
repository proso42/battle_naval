#include "../Includes/battle.h"

static void set_cross_color(t_data *info, char *id, int x, int y)
{
  if (!ft_strcmp("ia", id))
  {
    if (check_spy_ship(info->ia_spy_ship, x, y) ||
      check_destroyer(info->ia_destroyer, x, y) ||
      check_submarine(info->ia_submarine, x, y) ||
      check_cruiser(info->ia_cruiser, x, y) ||
      check_aircraft(info->ia_aircraft, x, y))
      ft_printf("{bold}{red}");
    else
      ft_printf("{bold}{cyan}");
  }
  else
  {
    if (check_spy_ship(info->player_spy_ship, x, y) ||
      check_destroyer(info->player_destroyer, x, y) ||
      check_submarine(info->player_submarine, x, y) ||
      check_cruiser(info->player_cruiser, x, y) ||
      check_aircraft(info->player_aircraft, x, y))
      ft_printf("{bold}{red}");
    else
      ft_printf("{bold}{cyan}");
  }
}

void print_map(t_data *info, char *id, char map[11][11])
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
        if (map[i][j] == 'X')
          set_cross_color(info, id, j, i);
        else
          ft_printf("{bold}{cyan}");
        ft_printf("%c {res}", map[i][j]);
        j++;
      }
      j = 0;
      i++;
      write(0, "\n", 1);
    }
}

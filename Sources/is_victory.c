#include "../Includes/battle.h"

static int  is_ia_looser(t_data *info)
{
  if (ft_strchr(info->ia_spy_ship->slot, 'O'))
    return (0);
  else if (ft_strchr(info->ia_destroyer->slot, 'O'))
    return (0);
  else if (ft_strchr(info->ia_submarine->slot, 'O'))
    return (0);
  else if (ft_strchr(info->ia_cruiser->slot, 'O'))
    return (0);
  else if (ft_strchr(info->ia_aircraft->slot, 'O'))
    return (0);
  return (1);
}

static int  is_player_looser(t_data *info)
{
  if (ft_strchr(info->player_spy_ship->slot, 'O'))
    return (0);
  else if (ft_strchr(info->player_destroyer->slot, 'O'))
    return (0);
  else if (ft_strchr(info->player_submarine->slot, 'O'))
    return (0);
  else if (ft_strchr(info->player_cruiser->slot, 'O'))
    return (0);
  else if (ft_strchr(info->player_aircraft->slot, 'O'))
    return (0);
  return (1);
}

int   is_victory(t_data *info)
{
  if (is_ia_looser(info))
  {
    ft_printf("{bold}{green}Vous avez gagn%s !{res}\n", "é");
    return (1);
  }
  else if (is_player_looser(info))
  {
    ft_printf("{bold}{red}Vous avez perdu !{res}\n");
    return (1);
  }
  return (0);
}

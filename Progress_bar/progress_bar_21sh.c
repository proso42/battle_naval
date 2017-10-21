/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:41:27 by proso             #+#    #+#             */
/*   Updated: 2017/06/05 13:20:25 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <termios.h>
#include <term.h>
#include "../Includes/libft.h"
#define CURSE_MOVE(x, y) tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ft_out)

void		open_sources(char *path, int *total, int *nb)
{
	DIR				*dirp;
	struct dirent	*buf;
	int				size;

	dirp = opendir(path);
	while ((buf = readdir(dirp)))
	{
		size = (int)ft_strlen(buf->d_name) - 1;
		if (buf->d_name[size] == 'o' && buf->d_name[size - 1] == '.')
			(*nb)++;
		if (buf->d_name[size] == 'c' && buf->d_name[size - 1] == '.')
			(*total)++;
	}
	closedir(dirp);
}

int			ft_out(int c)
{
	write(0, &c, 1);
	return (1);
}

int			def_term(struct termios *d_term, int total)
{
	if ((tcsetattr(0, TCSADRAIN, d_term)) == -1)
		return (0);
	if (!total)
		tputs(tgetstr("ve", NULL), 0, ft_out);
	return (1);
}

int			init_term(struct termios *term, struct termios *d_term)
{
	if (!(tgetent(NULL, "xterm-256color")))
		return (0);
	if ((tcgetattr(0, term)) == -1)
		return (0);
	if ((tcgetattr(0, d_term)) == -1)
		return (0);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSADRAIN, term)) == -1)
		return (0);
	tputs(tgetstr("vi", NULL), 0, ft_out);
	return (1);
}

int			main(int argc, char **argv)
{
	int				nb;
	int				total;
	struct termios	term;
	struct termios	d_term;

	(void)argc;
	nb = 0;
	total = 0;
	open_sources("Sources/", &total, &nb);
	total -= nb;
	init_term(&term, &d_term);
	tputs(tgetstr("cl", NULL), 0, ft_out);
	CURSE_MOVE(0, 0);
	ft_printf("{blue}{bold}%s ✓{res}", argv[1]);
	CURSE_MOVE(0, 1);
	ft_printf("{yellow}{bold}Progress :{res}");
	ft_printf("{GREEN}{bold}%*s{res}", nb, "");
	ft_printf("{RED}{bold}%*s{res}\n", total, "");
	def_term(&d_term, total);
	return (0);
}

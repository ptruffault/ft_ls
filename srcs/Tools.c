#include "../includes/ft_ls.h"

int		get_total(t_file *file)
{
	int total;

	total = 0;
	while ((file))  
	{
		total = total + file->block;
		file = file->next;
	}
	return(total/2);
}

void	ft_in_tabulation(char type, int n)
{
	char *color_str;

	while (--n > 0)
		ft_putstr("|  ");
	if ((type == 'd' && !(color_str = ft_strjoin(VERT ,"|-> ")))
	||	(type == 'l' && !(color_str = ft_strjoin(MAGENTA ,"|->")))
	|| ((type != 'd' && type != 'l') && !(color_str = ft_strjoin(NORMAL ,"|-> "))))
		ft_putstr_color_fd("ft_ls : probléme de gestion des couleurs", MAGENTA, 2);
	ft_putstr(color_str);
	free(color_str);
}

void	ft_print_error(char *error, char *param)
{
	if (error != NULL)
	{
		ft_putstr_fd("ft_ls :", 2);
		ft_putstr_fd(error, 2);
	}
	if (param != NULL)
	{
		ft_putchar_fd(' ', 2);
		ft_putchar_fd('\'', 2);
		ft_putstr_fd(param, 2);
		ft_putchar_fd('\'', 2);
	}
	ft_putchar('\n');
	exit(-1);
}


void	ft_rect(char *str, int tab)
{
	while (--tab > 0)
		ft_putstr("|  ");
	ft_putstr_color("|\0", ROUGE);
	ft_putstr_color(str, SOULIGNE);
	ft_putchar('\n');
}

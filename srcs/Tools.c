#include "../includes/ft_ls.h"

void		ft_disp_l(t_file *file, t_opts *options)
{
	char *date;

	ft_putchar(file->type);
	ft_putstr_color(file->mode, CYAN);
	ft_putchar(' ');
	ft_putnbr(file->nb_of_l);
	ft_putchar(' ');
	if (options->g == 0)
	{
		ft_putstr_color(file->owner, NORMAL);
		ft_putchar('\t');
	}
	ft_putstr_color(file->group, NORMAL);
	ft_putchar('\t');
	ft_putnbr(file->size);
	ft_putchar('\t');
	if ((options->u == 0 && !(date = ft_strsub(ctime(&file->modif_time), 4, 12)))  ||
		(options->u == 1 && !(date = ft_strsub(ctime(&file->access_time), 4, 12))))
		ft_print_error("ft_ls : allocation failed", NULL);
	else
	{
		ft_putstr_color(date, SOULIGNE);
		ft_putchar(' ');
		free(date);
	}
}

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
#include "../includes/ft_ls.h"

static void		ft_disp_l(t_file *file, t_opts *options)
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
		ft_putendl_fd("ft_ls : allocation failed", 2);
	else
	{
		ft_putstr_color(date, SOULIGNE);
		ft_putchar(' ');
		free(date);
	}
}

static void		disp_gr(t_file *file, t_opts *options)
{
	int n;

	ft_rect(file->name, options->tab);
	options->tab++;
	disp(file->sdir, options);
	n = options->tab;
	options->tab--;
	while (--n > 0)
		ft_putstr("|  ");
	ft_putchar('\n');
}

static void		aff(t_file *file, t_opts *options)
{
	if (options->tab != 0)
		ft_in_tabulation(file->type , options->tab);
	if (options->l == 1 || options->g == 1)
		ft_disp_l(file, options);
	if (options->p == 1)
		ft_putstr_color(file->path, JAUNE);
	else
		ft_putstr_color(file->name, NORMAL);
	if (file->type == 'l' && options->l == 1)
	{
		ft_putstr(" -> ");
		ft_putstr_color(file->link, CYAN);
	}
	ft_putchar('\n');
}
static void		disp_dir(t_file *file, t_opts *options)
{
	while (file)
	{
		if ((file->name) && (options->a == 1 || *file->name != '.')
		&& (options->gr == 1 && file->type == 'd' && (file->sdir) && (options->tab != 0)))
			disp_gr(file, options);
		else if ((file->name) && (options->a == 1 || *file->name != '.') && 
			(file->type == 'd' || options->d == 0))
			aff(file, options);
		file = file->next;
	}
}

void		disp(t_file *file, t_opts *options)
{
	if (options->nb_of_arg != 0 && file->type == 'd' && (file->sdir))
	{
		ft_rect(file->name, options->tab - 1);
		disp(file->sdir, options);
	}
	else
		disp_dir(file, options);
	if (options->tab == 0 && options->gr == 1)
	{
		while (file)
		{
			if (file->type == 'd' && (options->a == 1 || *file->name != '.') 
				&& (file->sdir))
			{
				ft_putchar('\n');
				ft_putstr(file->path);
				ft_putstr(":\n");
				disp(file->sdir, options);
			}
			file = file->next;
		}
		
	}
}
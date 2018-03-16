#include "../includes/ft_ls.h"

static void	ft_disp_l2(t_file *file, t_opts *options)
{
	char *date;

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

void		ft_disp_l(t_file *file, t_opts *options)
{
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
	ft_disp_l2(file, options);
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

static t_file *reverse_list(t_file *head)
{
    t_file *prev = NULL;
    t_file *next;

    while (head != NULL) 
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return (prev);
}

t_file	*recursif_sort(t_file *file, t_opts *options)
{
	t_file *tmp;

	if (options->t == 1 && options->u == 1)
		file = ft_sort_tfile(file, &ft_test_u);
	else if (options->t == 1 && options->u == 0)
		file = ft_sort_tfile(file, &ft_test_t);
	else if (options->s == 1)
		file = ft_sort_tfile(file, &ft_test_s);
	else if (options->t == 0 && options->u == 0)
		file = ft_sort_tfile(file, &ft_test_a);
	if (options->r == 1)
		file = reverse_list(file);
	tmp = file;
	while (tmp)
	{
		if (tmp->type == 'd' && (tmp->sdir) && (options->a == 1 || *tmp->name != '.'))
			tmp->sdir = recursif_sort(tmp->sdir, options);
		tmp = tmp->next;
	}
	return (file);
}
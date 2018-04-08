/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:40:09 by ptruffau          #+#    #+#             */
/*   Updated: 2018/04/08 15:44:13 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_in_tabulation(char type, int n)
{
	char *color_str;

	while (--n > 0)
		ft_putstr("|  ");
	if ((type == 'd' && !(color_str = ft_strjoin(VERT, "|-> "))) ||
	(type == 'l' && !(color_str = ft_strjoin(MAGENTA, "|->"))) ||
	((type != 'd' && type != 'l') && !(color_str = ft_strjoin(NORMAL, "|-> "))))
		ft_print_error("ft_ls : allocation failed", NULL);
	if (color_str)
	{
		ft_putstr(color_str);
		free(color_str);
	}
}

static void	aff(t_file *file, t_opts *options)
{
	if (options->tab != 0)
		ft_in_tabulation(file->type, options->tab);
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

static void	disp_dir(t_file *file, t_opts *options)
{
	int n;

	while (file)
	{
		if ((file->name) && (options->a == 1 || *file->name != '.')
		&& (options->gr == 1 && file->type == 'd' &&
		(file->sdir) && (options->tab != 0)))
		{
			ft_print_dir_name(file, options);
			disp(file->sdir, options);
			n = options->tab;
			options->tab--;
			while (--n > 0)
				ft_putstr("|  ");
			ft_putchar('\n');
		}
		else if ((file->name) && (options->a == 1 || *file->name != '.') &&
			(file->type == 'd' || options->d == 0))
			aff(file, options);
		file = file->next;
	}
}

void		disp(t_file *file, t_opts *options)
{
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
				ft_putchar(':');
				if (options->l == 1 || options->g == 1)
				{
					ft_putstr("\t\tTotal: ");
					ft_putnbr(get_total(file->sdir));
				}
				ft_putchar('\n');
				disp(file->sdir, options);
			}
			file = file->next;
		}
	}
}

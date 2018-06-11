/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:42:59 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 17:50:02 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	free_opts(t_opts *opts)
{
	int i;

	i = 0;
	while (i < opts->nb_of_arg)
		free(opts->args[i++]);
	free(opts->args);
}

int			get_total(t_file *file)
{
	int total;

	total = 0;
	while ((file))
	{
		total = total + file->block;
		file = file->next;
	}
	return (total);
}

void		ft_print_dir_name(t_file *file, t_opts *options)
{
	int tab;

	tab = options->tab;
	while (--tab > 0)
		ft_putstr("|  ");
	ft_putstr_color("|\0", ROUGE);
	ft_putstr_color(file->name, SOULIGNE);
	ft_putchar(':');
	if (options->tab != 0)
		options->tab++;
	if (options->l == 1 || options->g == 1)
	{
		ft_putstr_color("\t\tTotal: ", VERT);
		ft_putnbr(get_total(file->sdir));
	}
	ft_putchar('\n');
}

static void	arguments(t_opts *options, t_file *file)
{
	int i;

	i = 0;
	while (i < options->nb_of_arg)
	{
		if ((file = ft_search_tfile(options->args[i], options->gr)))
		{
			if (file->type == 'd' && (file->sdir))
			{
				if (options->f == 0)
					file->sdir = recursif_sort(file->sdir, options);
				ft_print_dir_name(file, options);
				disp(file->sdir, options);
			}
			else
				disp(file, options);
			ft_free_tfile(file);
		}
		i++;
	}
	free_opts(options);
}

int			main(int argc, char **argv)
{
	t_opts options;
	t_file *file;

	options = get_options(argc, argv);
	file = NULL;
	if (options.nb_of_arg != 0)
		arguments(&options, file);
	else
	{
		file = ft_get_tfile(".", options.gr);
		if (options.f == 0)
			file = recursif_sort(file, &options);
		disp(file, &options);
		ft_free_tfile(file);
	}
	return (0);
}

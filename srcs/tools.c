/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:13:25 by ptruffau          #+#    #+#             */
/*   Updated: 2018/04/08 16:18:54 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_disp_l2(t_file *file, t_opts *opts)
{
	char *date;

	if (file->type == 'c' || file->type == 'b')
	{
		ft_putnbr(major(file->st_rdev));
		ft_putstr(" , ");
		ft_putnbr(minor((file->st_rdev)));
	}
	else
		ft_putnbr(file->size);
	ft_putchar('\t');
	if ((opts->u == 0 && !(date = ft_strsub(ctime(&file->modif_time), 4, 12)))
	|| (opts->u == 1 && !(date = ft_strsub(ctime(&file->access_time), 4, 12))))
		error("allocation failed", NULL);
	else
	{
		ft_putstr_color(date, SOULIGNE);
		ft_putchar(' ');
		free(date);
	}
}

void			ft_disp_l(t_file *file, t_opts *options)
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

static t_file	*reverse_list(t_file *head)
{
	t_file *prev;
	t_file *next;

	prev = NULL;
	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return (prev);
}

t_file			*recursif_sort(t_file *file, t_opts *options)
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
		if (tmp->type == 'd' && (tmp->sdir) &&
		(options->a == 1 || *tmp->name != '.'))
			tmp->sdir = recursif_sort(tmp->sdir, options);
		tmp = tmp->next;
	}
	return (file);
}

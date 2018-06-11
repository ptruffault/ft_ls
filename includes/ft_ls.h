/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:26:00 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 14:22:27 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>


typedef struct s_opts	t_opts;
struct	s_opts
{
	int		tab;
	int		l;
	int		s;
	int		a;
	int		r;
	int		t;
	int		p;
	int		d;
	int		g;
	int		f;
	int		u;
	int		gr;
	int		nb_of_arg;
	char	**args;
};

t_opts	get_options(int argc, char **argv);
t_file	*recursif_sort(t_file *file, t_opts *options);
int		ft_test_a(t_file *file, t_file *tmp);
int		ft_test_t(t_file *file, t_file *tmp);
int		ft_test_s(t_file *file, t_file *tmp);
int		ft_test_u(t_file *file, t_file *tmp);
void	disp(t_file *file, t_opts *options);
void	ft_print_dir_name(t_file *file, t_opts *options);
void	ft_print_error(char *error, char *param);
void	ft_disp_l(t_file *file, t_opts *options);
int		get_total(t_file *file);
void	warning(char *descript, char *opts);
void	error(char *descript, char *opts);
#endif

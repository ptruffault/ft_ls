/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 12:55:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/24 15:36:14 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"			
# include <stdlib.h> 			//malloc & free
# include <stdio.h>  			//perror
# include <dirent.h>			//opendir, closedir, readdir, DIR*	
# include <sys/stat.h>			//stat stuff
# include <errno.h>				//error numbers
# include <pwd.h>				//get owner of file
# include <grp.h>				//get group name of file
# include <time.h>				//time, ctime
# include <sys/types.h>			//uintmax_t, etc.
# include <sys/xattr.h>			//listxattr


typedef struct 	s_args t_args;
struct s_args
{
	char 			*arg;
	char 			*path;
	int 			done;
	t_args		 	*next;
};

typedef struct		s_opts
{
	int				tab;
	int				l;
	int				a;
	int				r;
	int				t;
	int 			p;
	int 			d;
	int 			g;
	int 			f;
	int 			u;
	int				gr;
	int 			nb_of_arg;
	char			**args;
}					t_opts;

int 		get_total(t_file *file);
void		free_opts(t_opts *opts);
void		ft_rect(char *str, int tab);
void 		ft_tabulation(int n);
void		ft_in_tabulation(char type, int n);
void		ft_print_error(char *error, char *param);

t_opts		get_options(int argc, char **argv);
t_file		*recursif_sort(t_file *file, t_opts *options);
void		disp(t_file *file, t_opts *options);
#endif

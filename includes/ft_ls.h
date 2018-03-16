#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"			
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

t_opts		get_options(int argc, char **argv);
t_file		*recursif_sort(t_file *file, t_opts *options);
void		disp(t_file *file, t_opts *options);
void		ft_print_dir_name(t_file *file, t_opts *options);
void		ft_print_error(char *error, char *param);
void		ft_disp_l(t_file *file, t_opts *options);
int			get_total(t_file *file);
#endif
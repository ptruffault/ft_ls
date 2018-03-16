#include "../includes/ft_ls.h"

static int 		ft_test_opts_2(char c, t_opts *opts)
{
	if (c == 'q')
		opts->tab = 1;
	if (c == 'p')
		opts->p = 1;
	if (c == 'd')
		opts->d = 1;
	if (c == 'g')
		opts->g = 1;
	if (c == 'f')
		opts->f = 1;
	if (c == 'u')
		opts->u = 1;
	if (c == 's')
		opts->s = 1;
	return (0);
}

static int 		ft_test_opts(char c, t_opts *opts)
{
	if (c != 'q' && c != 'l' && c != 'R' && c != 'r' && c != 'a' && c != 't' && c != 'p'
	 && c != 'd' && c != 'g' && c != 'f' && c != 'u'&& c != 's' && c != '-')
		return (-1);
	else
	{
		if (c == 'l')
			opts->l = 1;
		if (c == 'R')
			opts->gr = 1;
		if (c == 'r')
			opts->r = 1;
		if (c == 'a')
			opts->a = 1;
		if (c == 't')
			opts->t = 1;
		return(ft_test_opts_2(c, opts));
	}
}

static void		init_opts_2(t_opts *opts)
{
	opts->l = 0;
	opts->s = 0;
	opts->tab = 0;
	opts->p = 0;
	opts->g = 0;
	opts->gr = 0;
	opts->a = 0;
	opts->r = 0;
	opts->d = 0;
	opts->u = 0;
	opts->f = 0;
	opts->t = 0;
}

static void		init_opts(t_opts *opts, int argc, char **argv)
{
	int i;
	int j;

	init_opts_2(opts);
	opts->args = NULL;
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][0] != '-' || (argv[i][0] == '-' && argv[i][1] == '\0'))
			j++;			
		i++;
	}
	opts->nb_of_arg = j;
	if (j != 0 && !(opts->args = (char **)malloc(sizeof(char *) * j)))
		ft_print_error("ft_ls : allocation failed", NULL);
}

t_opts			get_options(int argc, char **argv)
{
	t_opts	opts;
	int i;
	int j;
	int k;

	i = 1;
	j = 0;
	init_opts(&opts, argc, argv);
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			k = 1;
			while (argv[i][k] != '\0')
			{
				if (ft_test_opts(argv[i][k], &opts) == -1)
					ft_print_error("ft_ls : invalid option", argv[i]);
				k++;
			}
		}
		else
			opts.args[j++] = ft_strdup(argv[i]);
		i++;
	}
	return (opts);
}
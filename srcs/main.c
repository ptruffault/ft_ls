#include "../includes/ft_ls.h"

void	free_opts(t_opts *opts)
{
	int i;

	i = 0;
	while (i <= opts->nb_of_arg)
		free(opts->args[i++]);
	free(opts->args);
}

void	arguments(t_opts *options, t_file *file)
{
	int i;

	i = 0;
	while (i < options->nb_of_arg)
	{
		if ((file = ft_search_tfile(options->args[i], options->gr)))
		{	
			if (file->type == 'd' && (file->sdir) && (options->r == 1 || options->t == 1))
				file->sdir = recursif_sort(file->sdir, options);
			disp(file, options);
		}
		ft_free_tfile(file);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_opts options;
	t_file file;

	options = get_options(argc, argv);
	if (options.nb_of_arg != 0)
		arguments(&options, file.next);
	else
	{
		file.next = ft_get_tfile(".", options.gr);
		if (((options.r == 1 || options.t == 1) ) && options.f == 0)
			file.next = recursif_sort(file.next, &options);
		disp(file.next, &options);
		ft_free_tfile(file.next);
	}
	free_opts(&options);
	return (0);
}
#include "../includes/ft_ls.h"

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

int		alpha(t_file *file, t_file *tmp)
{
	char *cpy1;
	char *cpy2;
	int ret;

	cpy1 = ft_caps_lock(file->name);
	cpy2 = ft_caps_lock(tmp->name);
	ret = (ft_strcmp(cpy1, cpy2) > 0 ? 1 : 0);
	free(cpy1);
	free(cpy2);
	return (ret);
}

int 	ft_test_u(t_file *file, t_file *tmp)
{
	if (file->access_time != tmp->access_time)
		return ((file->access_time > tmp->access_time ? 0 : 1));
	else
		return (alpha(file, tmp));
}

int		ft_test_t(t_file *file, t_file *tmp)
{
	if (file->modif_time != tmp->modif_time)
		return ((file->modif_time > tmp->modif_time ? 0 : 1));
	else
		return (alpha(file, tmp));
}

t_file	*recursif_sort(t_file *file, t_opts *options)
{
	t_file *tmp;

	if (options->t == 1 && options->u == 1)
		file = ft_sort_tfile(file, &ft_test_u);
	else if (options->t == 1 && options->u == 0)
		file = ft_sort_tfile(file, &ft_test_t);
	else if (options->t == 0 && options->u == 0)
		file = ft_sort_tfile(file, &alpha);
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
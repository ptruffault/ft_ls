#include "libft.h"

static int		alpha(t_file *file, t_file *tmp)
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

static t_file *test_upper(t_file *file, int (*f)(t_file *file, t_file *tmp))
{
	t_file *tmp;

	tmp = file;
	while (tmp)
	{
		if ((*f)(file, tmp) == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_put_tfile(t_file *file)
{
	while (file)
	{
		ft_putendl(file->name);
		file = file->next;
	}
}

static void	put_after_tmp(t_file *prev, t_file *file, t_file *tmp)
{
	prev->next = file->next;
	file->next = tmp->next;
	tmp->next = file;
}

static int		ft_sort_parcours(t_file *prev, int (*f)(t_file *file, t_file *tmp))
{
	int ret;
	t_file *file;
	t_file *tmp;

	file = prev->next;
	ret = 1;
	while (file->next)
	{
		if ((file->next) && (tmp = test_upper(file, f)))
		{
			ret = 0;
			put_after_tmp(prev, file, tmp);
			file = prev->next;
		}
		file = file->next;
		prev = prev->next;
	}
	return (ret);
}

t_file	*ft_sort_tfile(t_file *file, int (*f)(t_file *file, t_file *tmp))
{
	t_file *prev;
	int is_sort;

	if (!(*f))
		f = alpha;
	is_sort = 0;
	prev = ft_new_tfile();
	prev->next = file;
	while (is_sort == 0)
		is_sort = ft_sort_parcours(prev, f);
	file = prev->next;
	free(prev);
	return (file);
}

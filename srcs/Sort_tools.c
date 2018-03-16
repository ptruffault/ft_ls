#include "../includes/ft_ls.h"

int		ft_test_a(t_file *file, t_file *tmp)
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

int	ft_test_s(t_file *file, t_file *tmp)
{
	if (file->size != tmp->size)
		return ((file->size > tmp->size ? 0 : 1));
	else
		return (ft_test_a(file, tmp));	
}

int 	ft_test_u(t_file *file, t_file *tmp)
{
	if (file->access_time != tmp->access_time)
		return ((file->access_time > tmp->access_time ? 0 : 1));
	else
		return (ft_test_a(file, tmp));
}

int		ft_test_t(t_file *file, t_file *tmp)
{
	if (file->modif_time != tmp->modif_time)
		return ((file->modif_time > tmp->modif_time ? 0 : 1));
	else
		return (ft_test_a(file, tmp));
}
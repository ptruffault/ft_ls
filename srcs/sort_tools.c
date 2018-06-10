/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:48:42 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 14:26:29 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*ft_caps_lock(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strdup(str);
	while (ret[i])
	{
		ret[i] = ft_toupper(ret[i]);
		i++;
	}
	return (ret);
}

int			ft_test_a(t_file *file, t_file *tmp)
{
	return ((ft_strcmp(file->name, tmp->name) > 0 ? 1 : 0));
}

int			ft_test_s(t_file *file, t_file *tmp)
{
	if (file->size != tmp->size)
		return ((file->size > tmp->size ? 0 : 1));
	else
		return (ft_test_a(file, tmp));
}

int			ft_test_u(t_file *file, t_file *tmp)
{
	if (file->access_time != tmp->access_time)
		return ((file->access_time > tmp->access_time ? 0 : 1));
	else
		return (ft_test_a(file, tmp));
}

int			ft_test_t(t_file *file, t_file *tmp)
{
	if (file->modif_time != tmp->modif_time)
		return ((file->modif_time > tmp->modif_time ? 0 : 1));
	else
		return (ft_test_a(file, tmp));
}

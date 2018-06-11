/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_tfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:11:26 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 16:17:12 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*my_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i--;
	}
	return (NULL);
}

static char		*split_name(char *path)
{
	char *ptr;
	char *ret;

	if (((*path == '.' || *path == '/') && *(path + 1) == '\0')
		|| ft_strequ(path, "..") )
		return (ft_strdup("."));
	if ((ptr = my_strchr(path, '/')))
	{
		ret = ft_strdup(ptr + 1);
		*(ptr + 1) = '\0';
		return (ret);
	}





	return (NULL);
}

static t_file	*ft_find(t_file *file, char *name)
{
	t_file *prev;
	t_file *tmp;

	tmp = file;
	prev = ft_new_tfile();
	prev->next = tmp;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			ft_free_tfile(tmp->next);
			tmp->next = NULL;
			free(prev);
			return (tmp);
		}
		else
		{
			prev->next = tmp->next;
			ft_del_tfile(tmp);
			tmp = prev->next;
		}
	}
	free(prev);
	return (NULL);
}

t_file			*ft_search_tfile(char *path, int recursif)
{
	t_file	*file;
	t_file	*ret;
	char	*name;

	name = split_name(path);
	printf("NAME = %s\nPATH = %s\n", name , path);
	file = ft_get_tfile(path, 0);
	if (!(ret = ft_find(file, name)))
	{
		warning("no such file or directory", path);
		return (NULL);
	}
	if (ret->type == 'd')
		ret->sdir = ft_get_tfile(ret->path, recursif);
	free(name);
	return (ret);
}

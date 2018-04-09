/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:11:48 by ptruffau          #+#    #+#             */
/*   Updated: 2018/04/08 18:11:51 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file		*ft_new_tfile(void)
{
	t_file *new;

	new = NULL;
	if (!(new = (t_file *)malloc(sizeof(t_file))))
	{
		ft_putendl_fd("ft_new_tfile : allocation failed", 2);
		exit(-1);
	}
	new->type = '?';
	new->next = NULL;
	new->sdir = NULL;
	new->name = NULL;
	new->path = NULL;
	new->mode = NULL;
	new->link = NULL;
	new->group = NULL;
	new->owner = NULL;
	return (new);
}

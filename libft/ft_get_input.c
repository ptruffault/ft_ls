/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:32:44 by ptruffau          #+#    #+#             */
/*   Updated: 2018/04/08 17:33:38 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_input(void)
{
	int		ret;
	char	buff;
	char	*input;
	int		i;

	input = ft_strnew(1);
	i = 0;
	while ((ret = read(0, &buff, 1)) && buff != '\n')
	{
		input[i++] = buff;
		input = ft_realloc(input, i, i + 1);
	}
	input[i] = '\0';
	if (!ret)
	{
		free(input);
		ft_putendl_fd("ft_get_input : read() failure", 2);
		return (NULL);
	}
	return (input);
}

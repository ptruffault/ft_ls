#include "../includes/libft.h"

int	ft_ismaj(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
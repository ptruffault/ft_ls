#include "../includes/libft.h"

void	ft_putchar_color_fd(char c , char *color, int fd)
{
	ft_putstr_fd(color, fd);
	ft_putchar_fd(c, fd);
	ft_putstr_fd(NORMAL, fd);
}

void	ft_putchar_color(char c , char *color)
{
	ft_putchar_color_fd(c, color, 1);
}
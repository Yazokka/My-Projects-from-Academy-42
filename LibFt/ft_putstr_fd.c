#include "libft.h"

void ft_putstr_fd(char const *s,int fd)
{
	int index;

	index = 0;
	while (s + index != NULL && s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}
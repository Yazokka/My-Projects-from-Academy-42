#include "libft.h"

void ft_putstr(char const *s)
{
	int index;

	index = 0;
	if (s != NULL)
	while (s[index] != '\0')
	{
		ft_putchar(s[index]);
		index++;
	}
}
#include "libft.h"

void ft_striter(char *s, void (*f)(char *))
{
	int index = 0;

	if (s == NULL || f == NULL)
		return ;
	while(s[index])
	{
		f(&s[index]);
		index++;
	}
}
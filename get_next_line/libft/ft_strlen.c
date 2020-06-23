#include "libft.h"
#include <string.h>

size_t ft_strlen(const char *str)
{
	int index;
	const char *cur;

	cur = str;

	index = 0;
	while(cur[index])
		index++;

	return (index);
}
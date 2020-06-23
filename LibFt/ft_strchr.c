#include "libft.h"
#include <string.h>

char *ft_strchr(const char *s, int c)
{
	char *ret;

	ret = (char *)s;
	while(*ret != c)
	{
		if (*ret == '\0')
			return (NULL);
		ret++;
	}
	return (ret);
}
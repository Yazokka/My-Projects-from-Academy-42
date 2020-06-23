#include "libft.h"
#include <stdlib.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ret;
	size_t index;

	index = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	ret = (char *)malloc(sizeof(*ret) * len + 1);
	if (ret == NULL)
		return (NULL);

	while (len != 0)
	{
		ret[index] = s[start];  
		index++;
		len--;
		start++;
	}
	ret[index] = '\0';
	return (ret);
}
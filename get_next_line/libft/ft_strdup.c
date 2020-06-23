#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
	char *copy;
	int count;
	int index;

	index = 0;
	count = 0;
	while(s1[index])
	{
		index++;
		count++;
	}

	copy = (char *)malloc(sizeof(*copy) * count + 1);
	if (copy == NULL)
		return (NULL);
	index = 0;

	while (s1[index])
	{
		copy[index] = s1[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}
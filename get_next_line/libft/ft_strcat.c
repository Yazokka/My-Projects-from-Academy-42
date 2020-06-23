#include "libft.h"

char *ft_strcat(char *restrict s1, const char *restrict s2)
{
	char *str1;
	char *str2;

	str1 = s1;
	str2 = (char *)s2;

	while (*str1 != '\0')
		str1++;
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (s1);
}
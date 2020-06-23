#include "libft.h"

void * ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
 {
 	char *csrc;
 	char *cdest;
 	size_t index;

 	if (n == 0 || dst == src)
 		return (dst);
 	csrc = (char *)src;
 	cdest = (char *)dst;
 	index = 0;
 	while (index < n)
 	{
 		cdest[index] = csrc[index];
 		index++;
 	}
 	return (cdest);
 }
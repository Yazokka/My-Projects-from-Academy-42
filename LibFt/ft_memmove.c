#include "libft.h"

void    *ft_memmove(void *str1, const void *str2, size_t n)
{
    unsigned char   *cstr1;
    unsigned char   *cstr2;
    size_t  i;
 
    cstr1 = (unsigned char *)str1;
    cstr2 = (unsigned char *)str2;
    i = -1;
    if (cstr2 < cstr1)
    {
        while ((int)(--n) >= 0)
            *(cstr1 + n) = *(cstr2 + n);
    }
    else
        while (++i < n)
            *(cstr1 + i) = *(cstr2 + i);
  return (str1);
}
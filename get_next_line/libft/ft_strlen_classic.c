#include "libft.h"

int ft_strlen_classic(char *str)
{
    int index;

    index = 0;
    while (str[index] != '\0')
        index++;
    return (index);
}

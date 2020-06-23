#include "libft.h"
#include <stdlib.h>

void ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
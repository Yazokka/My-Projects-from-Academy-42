#include "libft.h"

int	ft_isspaces(int c)
{
	if (c == '\t'
			|| c == '\n'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == '\b'
			|| c == ' ')
	{
		return (1);
	}
	return (0);
}
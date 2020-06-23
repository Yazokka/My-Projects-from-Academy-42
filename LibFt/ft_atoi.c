#include "libft.h"

static int checkforminus(const char *str, int index)
{
	if (str[index] == '-')
	{
		return (-1);
		index++;
	}
	return (1);
}

static int assignindex(const char *str, int index)
{
	if (str[index] == '-' || str[index] == '+')
		index++;
	return (index);
}

int ft_atoi(const char *str)
{
	int index;
	int sign;
	long int result;

	result = 0;
	sign = 1;
	index = 0;
	while ((str[index] == '\n' || str[index] == ' ' || str[index] == '\t' || str[index] == '\v' 
	|| str[index] == '\f' || str[index] == '\r') && str[index] != '\0')
		index++;
	sign = checkforminus(str, index);
	index = assignindex(str, index);
	while (ft_isdigit(str[index]) == 1)
	{
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483647 && sign == -1)
			return (0);
		result *= 10;
		result += (str[index] - '0');
		index++;
	}
	return ((int)result * sign);
}
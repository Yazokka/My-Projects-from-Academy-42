#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_file_existance(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Usage:\n./fillit [file]\n");
		return (0);
	}
	return (1);
}

int check_status(t_data *arr)
{
	if (arr->status == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

void print_map(t_data *arr, char **final)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j != arr->perfectnum)
	{
		while (i != arr->perfectnum)
		{
			ft_putchar(final[j][i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		j++;
	}
}
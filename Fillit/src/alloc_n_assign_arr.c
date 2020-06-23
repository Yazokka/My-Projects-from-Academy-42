#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_data *find_size(t_data *arr)
{
	int num;
	int index;

	index = 2;
	num = arr->numoftet * 4;
	while (index * index <= num)
		index++;
	arr->perfectnum = index;
	return (arr);
}

char **malloc_matrix(char **final, int num)
{
	int i;
	int j;
	int index;

	index = 0;
	i = 0;
	j = 0;

	final = (char **)malloc(sizeof(char *) * num);
	while (i <= num + 1)
	{
		final[i] = (char *)malloc(sizeof(char) * num);
		i++;
	}
	assign_dots(final, num);
	i = 0;
	j = 0;
	return (final);
}

void assign_dots(char **final, int num)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (j != num)
	{
		while (i != num)
		{
			final[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
}


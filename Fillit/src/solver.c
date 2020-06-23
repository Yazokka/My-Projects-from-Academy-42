#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **add_more_space(t_data *arr, char **final, int count)
{
	find_size(arr);
	arr->perfectnum += count;
	final = malloc_matrix(final, arr->perfectnum);
	return (final);
}

int put_tetri(t_data *arr, char **final, int vec[2], int index)
{
	int status;

	status = 0;
	if (final[vec[0] + arr[index].coords[0][0]][vec[1] + arr[index].coords[0][1]] == '.')
	{
		if (final[vec[0] + arr[index].coords[1][0]][vec[1] + arr[index].coords[1][1]] == '.')
		{
			if (final[vec[0] + arr[index].coords[2][0]][vec[1] + arr[index].coords[2][1]] == '.')
			{
				if (final[vec[0] + arr[index].coords[3][0]][vec[1] + arr[index].coords[3][1]] == '.')
				{
					status = 1;
				}
			}
		}
	}
	if (status == 1)
	{
		final[vec[0] + arr[index].coords[0][0]][vec[1] + arr[index].coords[0][1]] = arr->letter;
		final[vec[0] + arr[index].coords[1][0]][vec[1] + arr[index].coords[1][1]] = arr->letter;
		final[vec[0] + arr[index].coords[2][0]][vec[1] + arr[index].coords[2][1]] = arr->letter;
		final[vec[0] + arr[index].coords[3][0]][vec[1] + arr[index].coords[3][1]] = arr->letter;
		arr->letter++;
	}
	return (status);
}

void remove_tet(t_data *arr, char **finarr)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (j != arr->perfectnum)
	{
		while (i != arr->perfectnum)
		{
			if (finarr[j][i] == arr->letter)
				finarr[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	arr->letter--;
}

int solve(t_data *arr, char **final, int index)
{
	int vec[2];

	vec[0] = 0;
	while(vec[0] < arr->perfectnum)
	{
		vec[1] = 0;
		while (vec[1] < arr->perfectnum)
		{
			if (put_tetri(arr, final, vec, index))
			{
				if (index == arr->numoftet - 1)
					return (1);
				else if (solve(arr, final, index + 1))
					return (1);
				else
					remove_tet(arr, final);
			}
			vec[1]++;
		}
		vec[0]++;
	}
	return (0);
}

char **init_solve(t_data *arr, char **final)
{
	while (solve(arr, final, 0) != 1)
	{
		free(final);
		arr->perfectnum++;
		final = malloc_matrix(final, arr->perfectnum);
	}
	return (final);
}



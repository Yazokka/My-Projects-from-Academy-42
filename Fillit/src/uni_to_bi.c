#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uni_to_bi(t_data *arr)
{
	int vec[3];
	int arrindex;

	arrindex = 0;
	vec[2] = 0;
	vec[0] = 0;
	vec[1] = 0;
	while (arrindex < arr->numoftet)
	{
		while (vec[0] < 4)
		{
			while (vec[1] < 4)
			{
				arr[arrindex].finarr[vec[0]][vec[1]] = arr[arrindex].structarr[vec[2]];
				vec[1]++;
				vec[2]++;
			}
			vec[2]++;
			vec[1] = 0;
			vec[0]++;
		}
		vec[2] = 0;
		vec[0] = 0;
		arrindex++;
	}
}

int findmin(t_data *arr, int arrindex)
{
	int a;
	int b;
	int c;
	int d;
	int count;

	count = 4;

	a = arr[arrindex].coords[0][1];
	b = arr[arrindex].coords[1][1];
	c = arr[arrindex].coords[2][1];
	d = arr[arrindex].coords[3][1];

	if (a < count)
		count = a;
	if (b < count)
		count = b;
	if (c < count)
		count = c;
	if (d < count)
		count = d;
	return (count);
}
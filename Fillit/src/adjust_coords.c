#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adjust_positions_first(t_data *arr, int arrindex)
{
	int count;

	count = 0;
	if (arr[arrindex].firstposition != 0)
		arr[arrindex].firstposition--;
	while (arr[arrindex].firstposition > 4)
	{
		arr[arrindex].firstposition -= 4;
		count++;
		arr[arrindex].firstposition--;
	}
	arr[arrindex].coords[0][0] = count;
	arr[arrindex].coords[0][1] = arr[arrindex].firstposition;
}

void adjust_positions_second(t_data *arr, int arrindex)
{
	int count;

	count = 0;
	if (arr[arrindex].secondposition != 0)
		arr[arrindex].secondposition--;
	while (arr[arrindex].secondposition > 4)
	{
		arr[arrindex].secondposition -= 4;
		count++;
		arr[arrindex].secondposition--;
	}
	arr[arrindex].coords[1][0] = count;
	arr[arrindex].coords[1][1] = arr[arrindex].secondposition;
}

void adjust_positions_third(t_data *arr, int arrindex)
{
	int count;

	count = 0;
	if (arr[arrindex].thirdposition != 0)
		arr[arrindex].thirdposition--;
	while (arr[arrindex].thirdposition > 4)
	{
		arr[arrindex].thirdposition -= 4;
		count++;
		arr[arrindex].thirdposition--;
	}
	arr[arrindex].coords[2][0] = count;
	arr[arrindex].coords[2][1] = arr[arrindex].thirdposition;
}

void adjust_positions_last(t_data *arr, int arrindex)
{
	int count;

	count = 0;
	if (arr[arrindex].lastposition != 0)
		arr[arrindex].lastposition--;
	while (arr[arrindex].lastposition > 4)
	{
		arr[arrindex].lastposition -= 4;
		count++;
		arr[arrindex].lastposition--;
	}
	arr[arrindex].coords[3][0] = count;
	arr[arrindex].coords[3][1] = arr[arrindex].lastposition;
}

void loop(t_data *arr)
{
	int index;

	index = 0;
	while (index != arr->numoftet)
	{
		adjust_positions_first(arr, index);
		adjust_positions_second(arr, index);
		adjust_positions_third(arr, index);
		adjust_positions_last(arr, index);
		index++;
	}
}
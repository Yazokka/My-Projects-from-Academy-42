#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap_first(t_data *arr, int arrindex)
{
	int coordx;
	int coordy;
	char temp;
	int count;

	count = 0;
	coordx = arr[arrindex].coords[0][1];
	coordy = arr[arrindex].coords[0][0];

	while (arr[arrindex].finarr[coordy - 1][coordx] == '.')
	{
		temp = arr[arrindex].finarr[coordy - 1][coordx];
		arr[arrindex].finarr[coordy - 1][coordx] = arr[arrindex].finarr[coordy][coordx];
		arr[arrindex].finarr[coordy][coordx] = temp;
		coordy--;
		arr[arrindex].coords[0][0]--;
		count++;
	}
	return (count);
}

void swap_second(t_data *arr, int arrindex, int count)
{
	int coordx;
	int coordy;
	char temp;
	int index;

	coordx = arr[arrindex].coords[1][1];
	coordy = arr[arrindex].coords[1][0];
	index = 0;

	while (index != count)
	{
		temp = arr[arrindex].finarr[coordy - 1][coordx];
		arr[arrindex].finarr[coordy - 1][coordx] = arr[arrindex].finarr[coordy][coordx];
		arr[arrindex].finarr[coordy][coordx] = temp;
		coordy--;
		arr[arrindex].coords[1][0]--;
		index++;
	}
}

void swap_third(t_data *arr, int arrindex, int count)
{
	int coordx;
	int coordy;
	char temp;
	int index;

	index = 0;
	coordx = arr[arrindex].coords[2][1];
	coordy = arr[arrindex].coords[2][0];

	while (index != count)
	{
		temp = arr[arrindex].finarr[coordy - 1][coordx];
		arr[arrindex].finarr[coordy - 1][coordx] = arr[arrindex].finarr[coordy][coordx];
		arr[arrindex].finarr[coordy][coordx] = temp;
		coordy--;
		arr[arrindex].coords[2][0]--;
		index++;
	}
}

void swap_last(t_data *arr, int arrindex, int count)
{
	int coordx;
	int coordy;
	char temp;
	int index;

	index = 0;
	coordx = arr[arrindex].coords[3][1];
	coordy = arr[arrindex].coords[3][0];

	while (index != count)
	{
		temp = arr[arrindex].finarr[coordy - 1][coordx];
		arr[arrindex].finarr[coordy - 1][coordx] = arr[arrindex].finarr[coordy][coordx];
		arr[arrindex].finarr[coordy][coordx] = temp;
		coordy--;
		arr[arrindex].coords[3][0]--;
		index++;
	}
}

void start_all(t_data *arr)
{
	int arrindex;
	int count;

	arrindex = 0;
	while (arrindex != arr->numoftet)
	{
		count = swap_first(arr, arrindex);
		swap_second(arr, arrindex, count);
		swap_third(arr, arrindex, count);
		swap_last(arr, arrindex, count);
		arrindex++;
	}
}
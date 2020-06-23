#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_first_left(t_data *arr, int arrindex, int count)
{
	int coordx;
	int coordy;
	char temp;
	int index;

	index = 0;
	coordx = arr[arrindex].coords[0][1];
	coordy = arr[arrindex].coords[0][0];

	while (index != count)
	{
		temp = arr[arrindex].finarr[coordy][coordx - 1];
		arr[arrindex].finarr[coordy][coordx - 1] = arr[arrindex].finarr[coordy][coordx];
		arr[arrindex].finarr[coordy][coordx] = temp;
		coordx--;
		arr[arrindex].coords[0][1]--;
		index++;
	}
}

void swap_second_left(t_data *arr, int arrindex, int count)
{
	int coordx;
	int coordy;
	char temp;
	int index;

	coordx = arr[arrindex].coords[1][1];
	coordy = arr[arrindex].coords[1][0];
	index = 0;

	while (index != count && arr[arrindex].finarr[coordy][coordx - 1] == '.')
	{
		temp = arr[arrindex].finarr[coordy][coordx - 1];
		arr[arrindex].finarr[coordy][coordx - 1] = arr[arrindex].finarr[coordy][coordx];
		arr[arrindex].finarr[coordy][coordx] = temp;
		coordx--;
		arr[arrindex].coords[1][1]--;
		index++;
	}
}

void swap_third_left(t_data *arr, int arrindex, int count)
{
	int coordx;
	int coordy;
	char temp;
	int index;

	index = 0;
	coordx = arr[arrindex].coords[2][1];
	coordy = arr[arrindex].coords[2][0];

	while (index != count && arr[arrindex].finarr[coordy][coordx - 1] == '.')
	{
		temp = arr[arrindex].finarr[coordy][coordx - 1];
		arr[arrindex].finarr[coordy][coordx - 1] = arr[arrindex].finarr[coordy][coordx];
		arr[arrindex].finarr[coordy][coordx] = temp;
		coordx--;
		arr[arrindex].coords[2][1]--;
		index++;
	}
}

void swap_last_left(t_data *arr, int arrindex, int count)
{
	int coordx;
	int coordy;
	char temp;
	int index;

	index = 0;
	coordx = arr[arrindex].coords[3][1];
	coordy = arr[arrindex].coords[3][0];

	while (index != count && arr[arrindex].finarr[coordy][coordx - 1] == '.')
	{
		temp = arr[arrindex].finarr[coordy][coordx - 1];
		arr[arrindex].finarr[coordy][coordx - 1] = arr[arrindex].finarr[coordy][coordx];
		arr[arrindex].finarr[coordy][coordx] = temp;
		coordx--;
		arr[arrindex].coords[3][1]--;
		index++;
	}
}

void start_all_left(t_data *arr)
{
	int arrindex;
	int count;

	arrindex = 0;
	count = 0;
	while (arrindex != arr->numoftet)
	{
		count = findmin(arr, arrindex);
		swap_first_left(arr, arrindex, count);
		swap_second_left(arr, arrindex, count);
		swap_third_left(arr, arrindex, count);
		swap_last_left(arr, arrindex, count);
		arrindex++;
	}
}
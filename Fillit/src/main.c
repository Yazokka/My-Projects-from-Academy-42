#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readandassign(char *carr, t_data *arr)
{
	int index;
	int arrindex;
	int box;

	index = 0;
	arrindex = 0;
	box = 0;

	while (carr[index] != '\0')
	{
		if (carr[index] == '\n' && carr[index + 1] == '\n' && carr[index + 2] != '\n')
		{
			arr[box].structarr[arrindex] = '\0';
			index += 2;
			arrindex = 0;
			box++;
		}
		arr[box].structarr[arrindex] = carr[index];
		index++;
		arrindex++;
	}
}

int numoftetrimino(char *arr)
{
	int count;
	int fincount;
	int index;

	index = 0;
	count = 0;
	fincount = 0;

	while(arr[index] != '\0')
	{
		if (arr[index] != '\n' && arr[index] != '\0')
			count++;
		if (count == 16)
		{
			count = 0;
			fincount++;
		}
		index++;
	}
	if (count != 0)
		return (0);
	return (fincount);
}

int verifynumofnewlines(char *str, int tetrinum)
{
	int index;
	int count;

	index = 0;
	count = 0;

	while (str[index])
	{
		if (str[index] == '\n')
			count++;
		index++;
	}
	if ((tetrinum % 2) == 0 && (count % 2) == 0)
		return (0);
	if	((tetrinum % 2) != 0 && (count % 2) != 0)
		return (0);
	return (1);
}

t_data *fin_validate(char *str, t_data *arr)
{
	int tetrinum;
	int temparrsize;

	temparrsize = 0;
	tetrinum = numoftetrimino(str);
	arr = malloc(sizeof(t_data) * tetrinum);
	if (verifynumofnewlines(str, tetrinum) == 0 || tetrinum == 0)
	{
		arr->status = 0;
		return (arr);
	}
	arr->numoftet = tetrinum;
	readandassign(str, arr);
	while (temparrsize != tetrinum)
	{
		arr[temparrsize] = validate_map(arr[temparrsize]);
		if (arr[temparrsize].status == 0)
		{
			arr->status = 0;
			return (arr);
		}
		temparrsize++;
	}
	return (arr);
}

int main(int argc, char **argv)
{
	int fd;
	t_data *arr;
	char **final;
	char *readfile;
	int status;

	status = 1;
	final = NULL;
	arr = NULL;
	if (check_file_existance(argc) == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	readfile = readdata(fd, argv[1]);
	arr = fin_validate(readfile, arr);
	if (check_status(arr) == 0)
		return (0);
	uni_to_bi(arr);
	loop(arr);
	start_all(arr);
	start_all_left(arr);
	arr = find_size(arr);
	final = malloc_matrix(final, arr->perfectnum);
	arr->letter = 'A';
	final = init_solve(arr, final);
	print_map(arr, final);
}
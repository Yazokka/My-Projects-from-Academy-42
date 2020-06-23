#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int find_file_size(char *argv)
{
	int fd;
	int index;
	char buff;

	index = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buff, 1) != 0)
		index++;
	close(fd);
	return (index);
}

char *readdata(int fd, char *argv)
{
	int index;
	char buff;
	char *arr;

	index = 0;
	arr = (char *)malloc(sizeof(char) * find_file_size(argv));
	while (read(fd, &buff, 1) != 0)
	{
		arr[index] = buff;
		index++;
	}
	arr[index] = '\0'; 
	return (arr);
}
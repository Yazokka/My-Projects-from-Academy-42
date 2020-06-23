#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_data countdots(t_data contents)
{
	int count;
	int index;

	index = 0;
	count = 0;
	while (contents.structarr[index])
	{
		if (contents.structarr[index] == '.')
			count++;
		index++;
	}
	if (count == 12)
		contents.status = 1;
	else
		contents.status = 0;
	return (contents);
}

t_data checktetrisymbol(t_data contents)
{
	while (contents.structarr[contents.firstposition] == '.' || contents.structarr[contents.firstposition] == '\n')
		contents.firstposition++;
	if (contents.structarr[contents.firstposition] != '#')
		contents.status = 0;
	while (contents.structarr[contents.lastposition] != '#')
		contents.lastposition--;
	contents.firstposition++;
	contents.lastposition++;
	return (contents);
}

t_data findsecondandthird(t_data contents)
{
	int index;

	index = 0;
	while (contents.structarr[index] != '#')
		index++;
	index++;
	while (contents.structarr[index] != '#')
		index++;
	index++;
	contents.secondposition = index;
	while (contents.structarr[index] != '#')
		index++;
	index++;
	contents.thirdposition = index;

	return (contents);
}

t_data assignandstartall(t_data contents)
{
	contents = countdots(contents);
	if (contents.status == 0)
		return (contents);
	contents = checktetrisymbol(contents);
	if (contents.status == 0)
		return (contents);
    contents = findsecondandthird(contents);
    if (contents.status == 0)
		return (contents);
    contents = countdifferences(contents);
	if (contents.status == 0)
		return (contents);
    return (contents);
}

t_data validate_map(t_data contents)
{
	int index;

	index = 0;
	contents.firstposition = 0;
	contents.lastposition = ft_strlen(contents.structarr);
	contents.status = 1;
	contents = assignandstartall(contents);
	return(contents);
}

#include "fillit.h"
#include <stdio.h>
#include <string.h>

t_data countdifferences(t_data contents)
{
	int diff1;
	int diff2;
	int diff3;

	diff1 = contents.secondposition - contents.firstposition;
	diff2 = contents.thirdposition - contents.secondposition;
	diff3 = contents.lastposition - contents.thirdposition;
	contents.status = 1;

	if ((diff1 > 5) || (diff2 > 5) || (diff3 > 5))
		contents.status = 0;
	if (((diff1 == diff2) && (diff2 == diff3)) && ((diff1 + diff2 + diff3) != 15))
		contents.status = 0;
	if ((diff1 == 2) || (diff2 == 2) || (diff3 == 2))
		contents.status = 0;
	if ((diff1 == 1) && (diff2 == 1) && (diff3 == 1))
		contents.status = 1;
	return (contents);
}
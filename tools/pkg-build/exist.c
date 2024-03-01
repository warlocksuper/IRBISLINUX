#include "unistd.h"
#include "stdio.h"
#include "string.h"


int main(int ac, char **av)
{
	if(ac > 1 )
	{
		char *fname =  av[1];
		if(access(fname, F_OK) == 0)
		{
			printf("1");
			return 0;
		}
	}
	printf("0");
	return 0;
}

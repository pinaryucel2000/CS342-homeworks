#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 

int main()
{
	int i;
	int n;
	
	n = fork();
	
	
	for (i = 0; i < 5; ++i) 
	{
		n = fork();
		if (n == 0) 
		{
			if (i % 2 == 0) 
			{
				exit(0);
			}
		}
	}
	
	printf("By\n");
	return 0;
}

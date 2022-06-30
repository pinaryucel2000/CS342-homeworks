#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 

int main()
{
	int x = 100;
	if (fork () == 0) 
	{
		x += 100;
		
		if (fork() == 0) 
		{
			x += 50;
			printf("%d\n", x);
		}
		else 
		{
			//exec (“/bin/ls”); // execute the ls program
			printf("%d\n", x);
		}
		
		printf("%d\n", x);
	}
	
	printf("%d\n", x);
	return 0;
}

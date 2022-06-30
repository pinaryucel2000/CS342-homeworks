#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 

int main()
{
	pid_t n1 = fork();
	
	if(n1 > 0) 
	{
		pid_t n2 = fork();
		
		if(n2 > 0) // parent
		{
			wait(NULL);
			wait(NULL);
		}
		else if(n2 == 0) // left child
		{
			execlp("/bin/ps", "ps", "aux",  NULL);
		}
	}
	else if(n1 == 0) // right child
	{
		execlp("/bin/ls", "ls", "-al",  NULL);
	}

	return 0;
}

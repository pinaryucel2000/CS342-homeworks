#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 

void createTree(int k)
{	
	if(k == 1)
	{
		return;
	}
	
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
			createTree(k - 1);
		}
	}
	else if(n1 == 0) // right child
	{
		createTree(k - 1);
	}
}

int main()
{
	int k = -1;
	
	while(k > 5 || k < 1)
	{
		printf("Please enter a value between 1 and 5\n");
		printf("k: ");
		scanf("%d", &k);
		printf("\n");	
	}

	createTree(k);
	
	printf("Process id: %d\n", getpid());
	
	return 0;
}

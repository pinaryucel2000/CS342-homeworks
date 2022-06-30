#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <fcntl.h> 

int main()
{
	int fd1 = open("file", O_RDONLY);
	int fd2 = open("anotherFile", O_WRONLY| O_CREAT, 00700); 
	
	char c;
	
	while (read(fd1, &c, 1) == 1)
	{
		write(fd2, &c, 1);
		write(fd2, &c, 1);
	}	
	
	close(fd1);
	close(fd2);
	
	return 0;
}

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
	int status;
	printf("Hello From parent\n");
	int rtnval=fork();
	int ppid=getppid();
	int pid=getpid();
	if(rtnval==-1)
	{
		printf("child not created\n");
	}
	else
		if (rtnval==0)
		{
			printf("Hello from child \n");
			printf("parent's id %d and id %d\n",ppid,pid);
		}
	else
	{
		printf("Hello from parent again\n");
		printf("parent's id %d and id %d\n",ppid,pid);
		wait(&status);
	}
	return 0;
}
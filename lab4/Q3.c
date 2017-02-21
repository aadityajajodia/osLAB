#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
	char myArray[20][20];
	int i=0;
	int j;
	char c[100];
	int status;
	for (i = 1; i <argc; i++)
	{
		strcpy(myArray[i-1],argv[i]);
	}
	

	int ret=fork();
	if(ret==0)
	{
		
		for(i=0;i<argc-2;i++)
			for(j=0;j<argc-2-i;j++)
				if(strcmp(myArray[j],myArray[j+1])>0)
				{
					
					strcpy(c,myArray[j]);
					strcpy(myArray[j],myArray[j+1]);
					strcpy(myArray[j+1],c);
				}
		printf("Soretd list is\n");
		for (i = 0; i <argc-1; i++)
		{
			printf("%s\n",myArray[i] );
		}
	

	}
	else
	{
		wait(&status);
		printf("Unsorted list is\n");
		for (i = 1; i <argc; i++)
		{
			printf("%s\n",argv[i] );
		}

	}

	return 0;
}
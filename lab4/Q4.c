#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
	int n;
	int status;
	char str[20][20];
	int i,j;
	printf("Enter number of words\n");
	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf("%s",str[i]);
	}
	int ret=fork();
	if(ret==0)
	{
		char c[20];
		for(i=0;i<n-1;i++)
			for(j=0;j<n-i-1;j++)
				if(strcmp(str[j],str[j+1])>0)
				{
					
					strcpy(c,str[j]);
					strcpy(str[j],str[j+1]);
					strcpy(str[j+1],c);
				}
		printf("Soretd list is\n");
		for (i = 0; i <n; i++)
		{
			printf("%s\n",str[i] );
		}
	

	}
	else
	{
		int second=fork();
		
		int min;
		if (second==0)
		{
			char c[20];
		for(i=0;i<n-1;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
				if(strcmp(str[min],str[j])>0)
				{
					min=j;
				}
			strcpy(c,str[min]);
			strcpy(str[min],str[i]);
			strcpy(str[i],c);
				
		}
		printf("Soretd list is\n");
		for (i = 0; i <n; i++)
		{
			printf("%s\n",str[i] );
		}
	
		}
		if (second>0)
		{
			wait(&status);
			printf("Unsorted list is\n");
			for (i = 0; i <n; i++)
			{
				printf("%s\n",str[i] );
			}
		}
		wait(&status);
		

	}
	
	return 0;
}
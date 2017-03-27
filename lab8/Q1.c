#include<stdio.h>
int n;
int m;
int space[20];
int spacecopy[20];
int values[20];
int process[20];
int i;
int j;
int temp;
int opt=0;
int flag=0;
void bestfit();

void firstfit();
void main()
{
	printf("Enter number of memory spaces");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter memory space");
		scanf("%d",&space[i]);	
	}
	printf("Enter number of process");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("Enter process memory req");
		scanf("%d",&values[i]);
	}
	while(opt!=3)
	{
		printf("1.Best Fit\n2.First Fit\n3.Exit");
		scanf("%d",&opt);
		switch (opt)
		{
			case 1:
			bestfit();
			break;
			case 2:
			firstfit();
			break;
			case 3:
			printf("See you soon. Bye bye");
			break;
			default:
			printf("Enter correct option");	
		}
	}
}
void firstfit()
{
	for(i=0;i<m;i++)
		process[i]=99;
	for(i=0;i<n;i++)
		spacecopy[i]=space[i];
	j=0;	
	for(i=0;i<m;i++)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(spacecopy[j]>=values[i])
			{
				flag=1;
				spacecopy[j]=spacecopy[j]-values[i];
				process[i]=j;
				break;		
			}
			
		}
		if(flag==0)
			printf("No space for process of size %d\n",values[i]);
	}	
	for(i=0;i<m;i++)
	{
		if(process[i]!=99)
		{
			printf("Process %d is allocated hole %d\n",i,process[i]);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("Hole %d had size %d now has size %d\n",i,space[i],spacecopy[i]);
	}

}
void bestfit()
{
	
	for(i=0;i<m;i++)
		process[i]=99;
	for(i=0;i<n;i++)
		spacecopy[i]=space[i];
	j=0;	
	for(i=0;i<m;i++)
	{
		flag=0;
		int min=0;		
		for(j=0;j<n;j++)
		{
			if(spacecopy[j]>spacecopy[min])
				min=j;
		}			
			
		for(j=0;j<n;j++)
		{
			if(spacecopy[j]>=values[i])
			{
				if(spacecopy[min]>=spacecopy[j])
				{
					min=j;
				}
				flag=1;					
			}
			
		}
		if(flag==1)
		{
			spacecopy[min]=spacecopy[min]-values[i];
			process[i]=min;
		}
	}	
	for(i=0;i<m;i++)
	{
		if(process[i]!=99)
		{
			printf("Process %d is allocated hole %d\n",i,process[i]);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("Hole %d had size %d now has size %d\n",i,space[i],spacecopy[i]);
	}
}




















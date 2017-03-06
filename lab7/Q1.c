#include<stdio.h>
int main(int argc, char* argv[])
{
	int n;
	int r;
	int i;
	int j;
	int allocat[10][10];
	int avail[10];
	int max[10][10];
	int need[10][10];
	int work[10];
	int finish[10];
	i=0;
	j=0;
	int flag=0,flag3=0,k=0,flag4=0,counter=0;
	int seq[10];
	
	printf("Enter number of process\n");
	scanf("%d",&n);
	printf("You entered number of process as %d\n",n);
	printf("Enter number of resources\n");
	scanf("%d",&r);
	printf("You entered number of resources as %d\n",n);
	for(i=0;i<r;i++)
		finish[i]=0;
	for(i=0;i<n;i++)
	{
		printf("Enter allocated resources for process %d\n",i);
		for(j=0;j<r;j++)
			scanf("%d",&allocat[i][j]);

	}
	printf("Allocated matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
			printf("%d\t",allocat[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		printf("Enter MAX resources for process %d\n",i);
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);

	}
	printf("MAX matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
			printf("%d\t",max[i][j]);
		printf("\n");
	}
	printf("Enter available resources at this momemt\n");
	for(i=0;i<r;i++)
		scanf("%d",&avail[i]);
	printf("Availabe resources at this moment are\n");
	for(i=0;i<r;i++)
    {


		printf("%d\t",avail[i]);
		work[i]=avail[i];
    }
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		need[i][j] = max[i][j] -allocat[i][j];
	}
	printf("Need matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
			printf("%d\t",need[i][j]);
		printf("\n");
	}

	i=0;
	j=0;
	flag4=0;
	while(1)
	{
		flag4=0;
		 counter=0;
		 while(counter<n)
		 {

			flag=0;
			if(finish[i]==0)
			{
				flag=1;
				for(k=0;k<r;k++)
					if(need[i][k]>work[k])
					{
						flag=0;
						break;
					}
			}

			if(flag==1)
			{

				finish[i]=1;
				for(k=0;k<r;k++)
					work[k]=work[k]+allocat[i][k];
				seq[j++]=i;
				flag4=1;


			}

			i=(i+1)%n;
			counter++;
		}
		if(flag4==0)
			break;
	}
	flag3=1;
	for(i=0;i<n;i++)
		if(finish[i]==0)
		{
			flag3=0;
			break;
		}
	if(flag3==1){
		printf("yes\n");
		printf("The safe sequence is\n");
		for (i = 0; i < n; ++i)
		{
			printf("P%d\n",seq[i] );
		}
		printf("Enter your request process number\n");
		int n1;
		scanf("%d",&n1);
		int req;
		printf("Enter your request\n");
		for(i=0;i<r;i++)
		{
			scanf("%d",&req);
			allocat[n1][i]=allocat[n1][i]+req;
			avail[i]=avail[i]-req;
			work[i]=avail[i];
		}	
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		need[i][j] = max[i][j] -allocat[i][j];
	}
	printf("Need matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
			printf("%d\t",need[i][j]);
		printf("\n");
	}

	i=0;
	j=0;
	flag4=0;
	while(1)
	{
		flag4=0;
		 counter=0;
		 while(counter<n)
		 {

			flag=0;
			if(finish[i]==0)
			{
				flag=1;
				for(k=0;k<r;k++)
					if(need[i][k]>work[k])
					{
						flag=0;
						break;
					}
			}

			if(flag==1)
			{

				finish[i]=1;
				for(k=0;k<r;k++)
					work[k]=work[k]+allocat[i][k];
				seq[j++]=i;
				flag4=1;


			}

			i=(i+1)%n;
			counter++;
		}
		if(flag4==0)
			break;
	}
	flag3=1;
	for(i=0;i<n;i++)
		if(finish[i]==0)
		{
			flag3=0;
			break;
		}
	if(flag3==1){
		printf("yes\n");
		printf("The safe sequence is\n");
		for (i = 0; i < n; ++i)
		{
			printf("P%d\n",seq[i] );
		}
	}
	else
		printf("no\n");

	}
	else
		printf("no\n");

}

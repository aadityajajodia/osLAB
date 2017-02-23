#include<stdio.h>
void swap(int *x, int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}

void main()
{
	int n;
	int pid[100];
	int at[100];
	int bt[100];
	int bt2[100];
	int i,j;
	int ct[100];
	int tat[100];
	int wt[100];	
	printf("Enter number of process");
	scanf("%d", &n);
	printf("You entered number  process as %d \n", n);
	for(i=0;i<n;i++)
		pid[i]=i;
	for(i=0;i<n;i++)
		printf("Process %d has id %d\n",i,pid[i]);	
	for(i=0;i<n;i++)
	{
		printf("Enter arrival time for process %d ",i);
		scanf("%d",&at[i]);
	}
	for(i=0;i<n;i++)
		printf("Process %d has arrival time %d\n",pid[i],at[i]);		
	for(i=0;i<n;i++)
	{
		printf("Enter burst time for process %d ",pid[i]);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
		printf("Process %d has burst time %d\n",pid[i],bt[i]);
	for (int i = 0; i < n; ++i)
	{
		bt2[i]=bt[i];
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(at[j]>at[j+1])
			{ 	
				swap(&at[j],&at[j+1]);
				swap(&pid[j],&pid[j+1]);
				swap(&bt[j],&bt[j+1]);
				swap(&bt2[j],&bt2[j+1]);
		
			}		
		}
	int compTime=at[0];
	i=0;
	while(1)
	{
		int min=i;
		j=i+1;
		while((at[j]<=compTime)&&(j<n))
		{
			if(bt[min]>bt[j])
				min=j;
			j++;
		}
		swap(&at[min],&at[i]);
		swap(&pid[min],&pid[i]);
		swap(&bt[min],&bt[i]);
		swap(&bt2[min],&bt2[i]);
		swap(&ct[min],&ct[i]);
		compTime++;
		ct[i]=compTime;
		bt[i]--;
		if(bt[i]==0)
			i++;
		if(i==n-1)
			break;
	}
	compTime+=bt[i];
	ct[i]=compTime;
	for(i=0;i<n;i++)
		printf("Process %d has completion time %d\n",pid[i],ct[i]);
	
	for(i=0;i<n;i++)
		tat[i]=ct[i]-at[i];
	for(i=0;i<n;i++)
		wt[i]=tat[i]-bt2[i];
	for(i=0;i<n;i++)
		printf("Process %d has turn around time %d\n",pid[i],tat[i]);
	for(i=0;i<n;i++)
		printf("Process %d has wating time %d\n",pid[i],wt[i]);
	
	
}


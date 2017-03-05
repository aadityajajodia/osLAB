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
	int i,j;
	int ct[100];
	int tat[100];
	int wt[100];
	int bt2[100];	
	int tq;
	int store[100];
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
		bt2[i]=bt[i];
	}
	for(i=0;i<n;i++)
		printf("Process %d has burst time %d\n",pid[i],bt[i]);
	printf("Enter time Quantum\n");
	scanf("%d",&tq);
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
	j=0;
	int k=0;
	int current=0;
	int t;
	
	while(1)
	{
		while(at[j]<=compTime&&j<n)
		{
			store[k]=pid[j];
			k++;
			j++;
		}
		for(i=current;i<k;i++)
		{
			for(t=0;t<n;t++)
				if(pid[t]==store[i])
					break;
			if(tq<bt2[t]&&bt2[t]!=0)
			{
				bt2[t]=bt2[t]-tq;
				compTime=compTime+tq;
				ct[t]=compTime;
				store[k++]=pid[t];
				current++;
				while(at[j]<=compTime&&j<n)
				{
					store[k]=pid[j];
					k++;
					j++;
				}
			}
			else if(bt2[t]!=0)
			{
				compTime+=bt2[t];
				ct[t]=compTime;
				bt2[t]=0;
				current++;
				
				while(at[j]<=compTime&&j<n)
				{
					store[k]=pid[j];
					k++;
					j++;
				}

			}
	
		}
		if(current>k||current==k)
					break;
	}
		

	for(i=0;i<n;i++)
		printf("Process %d has completion time %d\n",pid[i],ct[i]);
	
	for(i=0;i<n;i++)
		tat[i]=ct[i]-at[i];
	for(i=0;i<n;i++)
		wt[i]=tat[i]-bt[i];
	for(i=0;i<n;i++)
		printf("Process %d has turn around time %d\n",pid[i],tat[i]);
	for(i=0;i<n;i++)
		printf("Process %d has wating time %d\n",pid[i],wt[i]);
	
	
}





















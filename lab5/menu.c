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
	int compTime;
	int pid[100];
	int at[100];
	int bt[100];
	int bt2[100];
	int p[100];
	int i,j;
	int ct[100];
	int tat[100];
	int wt[100];
	int opt;	
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
	
	for(i=0;i<n;i++)
	{
		printf("Enter priority for process %d ",pid[i]);
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
		printf("Process %d has priority time %d\n",pid[i],p[i]);
		
	do
	{
		for(i=0;i<n;i++)
		{
			ct[i]=0;
			tat[i]=0;
			wt[i]=0;
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
				swap(&p[j],&p[j+1]);
		
			}		
		}
		
		printf("1.FCFS\n");
		printf("2.SJF with Preemption\n");
		printf("3.Priorty Scheduling without Preemption\n");
		printf("4.Round Robin\n");
		printf("5.break\n");
		printf("Enter option\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
			compTime=at[0];
			for(i=0;i<n;i++)
			{
				
				if(compTime<at[i])
				{
					ct[i]=at[i]+bt[i];
					compTime=ct[i];
				}
				else
				{
					
					compTime+=bt[i];		
					ct[i]=compTime;		
				}
			}
			break;
			

			case 2:
			compTime=at[0];
			i=0;
			while(1)
			{
				int min=i;
				j=i+1;
				while((at[j]<=compTime)&&(j<n))
				{
					if(bt2[min]>bt2[j])
						min=j;
					j++;
				}
				swap(&at[min],&at[i]);
				swap(&pid[min],&pid[i]);
				swap(&bt2[min],&bt2[i]);
				swap(&bt[min],&bt[i]);
				swap(&ct[min],&ct[i]);
				compTime++;
				ct[i]=compTime;
				bt2[i]--;
				if(bt2[i]==0)
					i++;
				if(i==n-1)
					break;
			}
			compTime+=bt2[i];
			ct[i]=compTime;
			break;


			case 3:
			compTime=at[0];
			for(i=0;i<n-1;i++)
			{
				compTime+=bt[i];
				ct[i]=compTime;
				j=i+1;
				int min=j;
				while((at[j]<compTime)&&(j<n-1))
				{

					if(p[min]>p[j+1])
					{
						min=j+1;
					}
					j++;
				}
				swap(&at[min],&at[i+1]);
				swap(&pid[min],&pid[i+1]);
				swap(&bt[min],&bt[i+1]);
				swap(&p[min],&p[i+1]);
			}
			compTime+=bt[i];
			ct[i]=compTime;
			break;

			case 5:
			printf("Bye Bye\n");
			break;

			default:
			printf("Enter correct option\n");

		}

		if(opt ==5)
			break;
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
		

	}while(opt!=5);
	
	
	
}





















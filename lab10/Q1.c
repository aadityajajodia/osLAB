#include<stdio.h>
int up;
int n;
int arr[20];
int distance;
int flag[20];
int smallest;
int i,j;
int h;
int tempindex;
int temph;
int p;
int opt;
void sstf();
void scan();
void cscan();
void clook();
void main()
{
	printf("Enter upper limit\n");
	scanf("%d",&up);
	printf("Enter number of enteries\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter cylinder number\n");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		flag[i]=0;
	}
	for( i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
	printf("Enter start head position\n");
	scanf("%d",&h);
	temph=h;
	printf("Enter previous head position\n");
	scanf("%d",&p);
	while(opt!=5)
	{
		printf("1.sstf\n2.scan\n3.c-scan\n4.c-look\n5.exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
			sstf();
			break;
			case 2:
			scan();
			break;
			case 3:
			cscan();
			break;
			case 4:
			clook();
			break;
			case 5:
			printf("See you again bye\n");
			break;
			default:
			printf("Enter correct option");
		}
	}
}
void sstf()
{	
	distance=0;
	int exit=1;
	int diff;
	int index;
	while(1)
	{

		exit=1;
		smallest=up;
		for(i=0;i<n;i++)
		{
			if(flag[i]==0&&arr[i]!=h)
			{
				
				exit=0;
				diff=arr[i]-h;
				if(diff<0)
					diff=diff*(-1);
				if(diff<smallest)
				{
					smallest=diff;
					index=i;
					
					
				}
			}
		}
		
		if(exit==1)
		{
			printf("total distance is %d\n",distance);
			break;
				
		}
		h=arr[index];
		flag[index]=1;
		printf("%d\n",h);
		distance+=smallest;	
		
	}
}
void scan()
{
	distance=0;
	if(h<p)
	{
		for(i=0;i<n;i++)
		{
			if(arr[i]>h)
			{
				tempindex=i-1;
				break;
			}
		}
		for(i=tempindex;i>=0;i--)
		{
			printf("%d\n",arr[i] );
			distance+=(temph-arr[i]);
			temph=arr[i];
		}
		printf("0\n");
		distance+=temph-0;
		temph=0;
		for(i=tempindex+1;i<n;i++)
		{
			printf("%d\n",arr[i] );
			distance+=arr[i]-temph;
			temph=arr[i];

		}
	}
	else
	{
		for(i=n-1;i>=0;i--)
		{
			if(arr[i]<h)
			{
				tempindex=i+1;
				break;
			}
		}
		for(i=tempindex;i<n;i++)
		{
			printf("%d\n",arr[i] );
			distance+=arr[i]-temph;
			temph=arr[i];
		}	
		printf("%d\n",up );
		distance+=up-temph;
		temph=up;
		for(i=tempindex-1;i>=0;i--)
		{
			printf("%d\n",arr[i] );
			distance+=temph-arr[i];
			temph=arr[i];
		}	
	}
	printf("total distace covered is%d\n",distance );
	
}
void cscan(){}
void clook(){}




















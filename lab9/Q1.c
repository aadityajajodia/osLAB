#include<stdio.h>
int fnum;
int pnum;
int parr[20];
int farr[5];
int count=-1;
int i,j;
int fault=0;
void main()
{
	printf("Enter number of frames\n");
	scanf("%d",&fnum);
	printf("Enter number of pages\n");
	scanf("%d",&pnum);
	for(i=0;i<pnum;i++)
	{
		printf("Enter page number\n");
		scanf("%d",&parr[i]);
	}
	for(i=0;i<fnum;i++)
		farr[i]=-1;
	for(i=0;i<pnum;i++)
	{
		int temp=parr[i];
		int flag=0;
		for(j=0;j<fnum;j++)
			if(temp==farr[j])
			{	
				flag=1;
				break;
			}
		if(flag==0)
		{
			fault++;
			count=(count+1)%fnum;
			farr[count]=temp;
		}
		for(j=0;j<fnum;j++)
			printf("%d\t",farr[j]);
		printf("\n");

	}
	printf("Number of fault = %d\n",fault );
}
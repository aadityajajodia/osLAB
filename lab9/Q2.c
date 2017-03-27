#include<stdio.h>
int fnum;
int pnum;
int parr[20];
int farr[5];
int farr2[5];
int count=-1;
int i,j,k;
int flag;
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
		flag=0;
		for(j=0;j<fnum;j++)
			if(farr[j]==parr[i])
			{
				flag=1;
				break;
			}
		if(flag==0)
		{
			fault++;
			for(j=0;j<fnum;j++)
				farr2[j]=99;
			for(j=i+1;j<pnum;j++)
			{
				for(k=0;k<fnum;k++)
					if(farr[k]==parr[j]&&farr2[k]==99)
						farr2[k]=j;
			}
			int largest=0;
			for(j=0;j<fnum;j++)
			{
				if(farr2[j]>farr2[largest])
					largest=j;
			}
			farr[largest]=parr[i];
			for(j=0;j<fnum;j++)
				printf("%d\t",farr[j]);
			printf("\n");
		}
		
	}
	printf("Number of fault = %d\n",fault );
}
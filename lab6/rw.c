#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define capacity 10
pthread_mutex_t rmutex,wrt;
pthread_t trid[10];
pthread_t twid[1];
int readcount=0;
	
void *writer()
{
	
	while(1)
	{
		
		pthread_mutex_lock(&wrt);
		
		printf("Writer is writing\n");		
		pthread_mutex_unlock(&wrt);			
	}
}
void *reader()
{
	while(1)
	{
		pthread_mutex_lock(&rmutex);
		readcount++;
		if(readcount==1)
			pthread_mutex_lock(&wrt);
		pthread_mutex_unlock(&rmutex);
		printf("Reader is reading\n");
		pthread_mutex_lock(&rmutex);
		readcount--;
		if(readcount==0)
			pthread_mutex_unlock(&wrt);
		pthread_mutex_unlock(&rmutex);	
	}
}
void main()
{
	pthread_mutex_init(&rmutex,NULL);
	pthread_mutex_init(&wrt,NULL);
	int i;
	for(i=0;i<1;i++)
	{
		pthread_create(&twid[i],NULL,writer,NULL);
	
	}
	for(i=0;i<10;i++)
	{
		pthread_create(&trid[i],NULL,reader,NULL);
	
	}
	
	
}	



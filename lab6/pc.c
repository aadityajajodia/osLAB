#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define capacity 10
sem_t mayproduce, mayconsume;

pthread_mutex_t pmutex,cmutex;
pthread_t tpid[10];
	pthread_t tcid[20];
	int i;
	int buffer[10];	
	int in=0;
	int out=0;
	
void *producer()
{
	int pitem;
	while(1)
	{
		sem_wait(&mayproduce);
		pitem=rand()%10;
		
		pthread_mutex_lock (&pmutex);
		buffer[in]=pitem;
		printf("Item produced is %d\n",buffer[in]);		
		in=(in%capacity)+1;
		pthread_mutex_unlock(&pmutex);
		sem_post(&mayconsume);			
	}
}
void *consumer()
{
	int citem;
	while(1)
	{
		sem_wait(&mayconsume);
		
		pthread_mutex_lock(&cmutex);
		citem=buffer[out];
		printf("Item consumed is %d\n",buffer[out]);
		out=(out%capacity)+1;
		pthread_mutex_unlock(&cmutex);
		sem_post(&mayproduce);			
	}
}
void main()
{
	
	sem_init(&mayproduce,1,capacity);
	sem_init(&mayconsume,1,0);
	
	pthread_mutex_init(&pmutex,NULL);
	pthread_mutex_init(&cmutex,NULL);
	
	for(i=0;i<10;i++)
	{
		pthread_create(&tpid[i],NULL,producer,NULL);
	
	}
	for(i=0;i<10;i++)
	{
		pthread_create(&tcid[i],NULL,consumer,NULL);
	
	}
	
}	



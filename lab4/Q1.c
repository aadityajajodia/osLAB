#include<stdio.h>
#include<unistd.h>
//#include<stdlib.h>
int main(int argc, char const *argv[])
{
	execlp("ls","",NULL);
	return 0;
}
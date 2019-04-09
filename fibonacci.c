#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int n,ans;
int n1 =0;
int n2=1;
int a[100];
int b[100];
int d[100];
int i;
void *fibb()
{
int ans;
printf("Thread 1 is created and started execution\n");
printf("Enter the number upto which u want the series:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
ans=n1+n2;
a[i]=n1;
n1= n2;
n2=ans;
}
printf("Thread 1 has sccesfully complted forming the series and stored it in the array \n");
printf("Thread 1 exitted\n");
pthread_exit(a);
}
void *f1(void * args)
{
printf("Thread 2 has been created and started executing....\n");
int *d=args;
printf("The fibonacci series for the choosen number is\t");
for(i=0;i<n;i++)
{
printf("%d\t",d[i]);
}
printf("Thread 2 has displayed the array and exitted succesfully the fibonacci series");
pthread_exit(NULL);
}
int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,fibb,NULL); //creating thread 1 
pthread_join(t1,NULL);              //joining thread 1 
int *b= a;
pthread_create(&t2,NULL,f1,b);      //creating thread 2 
pthread_join(t2,NULL);              //joining thread 2
return 0;
}

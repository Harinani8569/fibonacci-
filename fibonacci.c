#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>


int n;
int a[n];
int i;
void *fibb()
{
int n1 =0;
int n2=1;
int ans;



printf("Enter the number upto which u want the series:");

scanf("%d",&n);

for(i=0;i<n;i++)
{
//printf("%d",n1);
ans=n1+n2;
a[i]=n1;
n1= n2;
n2=ans;

}
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);

}

pthread_exit(a);



}
void *f1(void * args)
{
int d[n];
*d=args;
for( i=0;i<n;i++)
{
printf("%d\t",d[i]);
}
pthread_exit(NULL);

}
int main()
{
int num;
pthread_t t1,t2;


pthread_create(&t1,NULL,fibb,NULL);
pthread_join(t1,(void*)a);
int *b= a;

pthread_create(&t2,NULL,f1,b);
pthread_join(t2,NULL);


//printf("The num is %d",number);
return 0;

}

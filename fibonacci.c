#include<stdio.h>
#include<pthread.h>
void *fibonacci(void* args)
{
  int n1=0;
  int n2=1;
  int fib;
  int n,num;
  printf("Enter the num upto which you want the series");
  scanf("%d",num);
  for(int couht=0;count<num;++count)
  {
    fib=n1+n2;
    n1=n2;
    n2=fib;
  }
  int main()
  {
    pthread_t t1;
    pthread_create(&t1,NULL,&fibonacci,(void*)&n);
    pthread_join(t1,(void *)&fib);
    printf("The series is %d",fib);
  }

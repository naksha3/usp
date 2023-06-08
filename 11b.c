#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myNewThread(void *vargp){
 printf("Hello world\n");
}
void *myThreadFun(void *vargp)
{

int *myid = (int *)vargp;
 printf("%ld %ld ", pthread_self(), *myid);
 int maint = pthread_self();
if(maint == (*myid) )
 {
 int i,j;
 printf("main thread encountered\n");
 pthread_t nid;
 for (i = 0; i < 5; i++)
 for(j =0;j<5;j++)
 pthread_create(&nid, NULL, myNewThread, (void *)&nid);
 }
}
int main()
{
int i;
pthread_t tid;

for (i = 0; i < 2; i++)
pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
  pthread_exit(NULL);
return 0;
}

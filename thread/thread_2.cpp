#include<pthread.h>
#include<stdio.h>

void *thfunc(void *arg)
{
  int *pn = (int*)arg;
  int n = *pn;

  printf("int thfunc n=%d\n", n);
  return (void*)0;
}

int main(int argc, char **argv)
{
  pthread_t tidp;
  int ret, n=110;

  ret = pthread_create(&tidp, NULL, thfunc, &n);
  if(ret)
  {
    printf("pthread_create failed: %d\n", ret);
    return -1;
  }
  printf("int main: thread is createed\n");
  return 0;
}

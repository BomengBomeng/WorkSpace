#include<pthread.h>
#include<stdio.h>

typedef struct
{
  int n;
  char *str;
}MYSTRUCT;

void *thfunc(void *arg)
{
  MYSTRUCT *my = (MYSTRUCT*)arg;
  printf("int thfunc n=%d  str=%s\n", my->n, my->str);
  return (void*)0;
}

int main(int argc, char **argv)
{
  pthread_t tidp;
  int ret;
  MYSTRUCT my;
  my.n = 100;
  my.str = "hello world";

  ret = pthread_create(&tidp, NULL, thfunc, (void*)&my);
  if(ret)
  {
    printf("pthread_create failed: %d\n", ret);
    return -1;
  }
  pthread_join(tidp, NULL);
  printf("int main: thread is createed\n");
  return 0;
}

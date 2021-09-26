#include<pthread.h>
#include<stdio.h>

int gn=10;
void *thfunc(void *arg)
{
  gn++;
  printf("int thread: gn=%d\n",gn);
  return (void*)0;
}

int main(int argc, char ** argv)
{
  pthread_t tidp;
  int ret;
  ret = pthread_create(&tidp, NULL, thfunc, NULL);
  if(ret)
  {
    printf("phtread_create failed: %d", ret);
    return -1;
  }
  pthread_join(tidp, NULL);
  gn++;
  printf("int main: gn=%d\n", gn);
  return 0;
}

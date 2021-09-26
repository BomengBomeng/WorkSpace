#include<pthread.h>
#include<stdio.h>

void *thfunc(void *arg)
{
  char *str;
  str = (char*)arg;

  printf("int thfunc str=%s\n", str);
  return (void*)0;
}

int main(int argc, char **argv)
{
  pthread_t tidp;
  int ret;
  const char* str= "hello world!";

  ret = pthread_create(&tidp, NULL, thfunc, (void*)str);
  if(ret)
  {
    printf("pthread_create failed: %d\n", ret);
    return -1;
  }
  pthread_join(tidp, NULL);
  printf("int main: thread is createed\n");
  return 0;
}

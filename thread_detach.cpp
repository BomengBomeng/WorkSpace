#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void *thfunc(void *arg)
{
  sleep(10);
  cout << "sub thread is runing!" << endl;
  return nullptr;
}

int main(int argc, char **argv)
{
  pthread_t thread_id;
  pthread_attr_t thread_attr;
  struct sched_param thread_para;
  size_t stack_size;
  int res;

  res = pthread_attr_init(&thread_attr);
  if(res)
    cout << "thread_attr_init failed: " << res << endl;

  res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
  if(res)
    cout << "pthread_attr_setDetachstate faild: " << res << endl;

  res = pthread_create(&thread_id, &thread_attr, thfunc, nullptr);
  if(res)
    cout << "pthread_create faild: " << res <<endl;
  cout <<  "main thread will exit!" << endl;
  pthread_exit(nullptr);
  cout <<  "if main thread has exited this line will not run" << endl;
  return 0;
}

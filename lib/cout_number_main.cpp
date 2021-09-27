extern void f(int num);   //外部函数的声明
#include<iostream>
int main(){
  f(66);
  std::cout << "HI" << std::endl;
  return 0;
}

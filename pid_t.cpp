#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
    pid_t pid = getpid();
    cout << sizeof(pid_t) << endl;
    cout << pid << endl;
    int i;
    cin >> i;
    return 0;
}

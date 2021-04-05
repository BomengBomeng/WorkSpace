#include"MyArray.hpp"

void test01(){
	MyArray<int> arr(5);
	for(int i=0; i<5; i++)
		arr.push_back(i);
	for(int i=0; i<5; i++)
		cout << arr[i] << " ";
	cout << endl;

}

int main(){
	test01();
	return 0;
}

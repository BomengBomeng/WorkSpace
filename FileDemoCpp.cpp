#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
	ofstream fout("data.dat",ios::out);
	fout << "this is the demo of file" << endl << "try it my self" << endl << "get the result" << endl;
	fout.close();
	ifstream fin;
	fin.open("data.dat",ios::in);
	if(!fin.is_open()){
		cout << "ERROR" << endl;
		return -1;
	}

	//input methead 1
	char c;
	while((c=fin.get())!=EOF)
		cout << c;
	fin.close();
	
	//input methead 2
	fin.open("data.dat",ios::in);
	char buf[2] = {0}; //in words   overflow without warning
	while(fin>>buf)
		cout << buf << " ";
	cout << endl;
	fin.close();
	
	//input methead 3
	fin.open("data.dat",ios::in);
	char buff[100];
	while(fin.getline(buff,sizeof(buff)))
		cout << buff << endl;
	fin.close();
	
	//input methead 4
	fin.open("data.dat",ios::in);
	string buffer;
	while(getline(fin,buffer))
		cout << buffer << endl;


	fin.close();
	return 0;
}

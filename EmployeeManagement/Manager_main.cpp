#include<iostream>
#include"WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;

void test01(WorkerManager mv){
	Worker *w = new Employee(128,"zhangsan",0);
	w->ShowInfo();	
	Worker *x = new Manager(127,"zgsan",1);
	x->ShowInfo();	
	Worker *y = new Boss(126,"zhann",3);
	y->ShowInfo();
	
	for(int i=0; i<mv.m_EmpNum; i++)
		cout << mv.m_EmpArry[i]->m_Id << mv.m_EmpArry[i]->m_Name << mv.m_EmpArry[i]->m_DeptId << endl;
	cout << "-------------------" << mv.m_EmpNum << "  " << mv.m_FileIsEmpty << endl;
}

int main(){
	system("clear");
	WorkerManager mv;
	//test01(mv);

	int choice;
	char ch;
	while(true){
		mv.Show_Menu();
		cout << "please choose the operatioin: ";
		cin >> choice;
		switch(choice){
			case 0:
				mv.ExitSystem();
				break;
			case 1: mv.Add_Emp();
				mv.save();
				cout << endl << "input anything to go back: ";
				cin>>ch;
				break;
			case 2: mv.show_Emp();
				cout << endl << "input anything to go back: ";
				cin>>ch;
				break;
			case 3:	{	int numb;
					cout << "intput the id you want to delet: ";
					cin >> numb;
					mv.Del_Emp(numb);
					mv.save();
					cout << endl << "input anything to go back: ";
					cin >> ch;
					break;	
				}
			case 4: {
					int numb;
					cout << "intput the id you want to medify: ";
					cin >> numb;
					mv.Medify_Emp(numb);
					mv.save();
					cout << endl << "input anything to go back: ";
					cin >> ch;
					break;	
				}
			case 5:
				{
					int mode;
					cout << "choose search mode (0.ID 1.name): ";
					point:cin >> mode;
					switch(mode){
						case 0: {
							int id;
							cout << "please input the id: ";
							cin >> id;
							mv.search_by_ID(id);
							break;
							}
						case 1: {
							string name;
							cout << "please intput the name: ";
							cin >> name;
							mv.search_by_Name(name);
							break;
							}
						default:cout << "input error! try againe ";
							goto point;
					}
					cout << endl << "input anything to go back: ";
					cin >> ch;
					break;	
				}
			case 6:	mv.Sort_by_ID();
				mv.save();	
				cout << endl << "input anything to go back: ";
				cin >> ch;
				break;
			case 7: {
				mv.Clean();
				cout << endl << "input anything to go back: ";
				cin >> ch;
				break;
				}
		}
		system("clear");
	}	
	return 0;
}

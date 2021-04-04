#include"Manager.h"

Manager :: Manager(int id, string name, int deptid){
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Manager :: ShowInfo(){
	cout << "ID: " << m_Id;
	cout << "\t\tNAME: " << m_Name;
	cout << "\t\tpersition: " << this->getDeptName() << endl;
}
string Manager :: getDeptName(){
	return "manager";
}

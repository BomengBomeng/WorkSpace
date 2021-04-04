#include"Employee.h"

Employee :: Employee(int id, string name, int deptid){
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptid;
}

void Employee :: ShowInfo(){
	cout << "ID: " << m_Id;
	cout << "\t\tNAME: " << m_Name;
	cout << "\t\tpersition: " << this->getDeptName() << endl;
}
string Employee :: getDeptName(){
	return "employee";
}

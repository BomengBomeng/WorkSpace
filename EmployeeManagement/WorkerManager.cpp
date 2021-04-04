#include"WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"


WorkerManager::WorkerManager(){
	ifstream fin;
	fin.open(FILENAME,ios::in);
	if(!fin){
		cout << "***there is no data file!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileIsEmpty = true;
		fin.close();
		return;
	}
	char ch;
	fin >> ch;
	if(fin.eof()){
		cout << "***the data file is empty!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileIsEmpty = true;
		fin.close();
		return;
	}
	int num = getFileNum(fin);
	cout << "There are " << num << " contents in the data file!" << endl;
	init_Emp(num);
}

WorkerManager::~WorkerManager(){
	if(this->m_EmpArry!=NULL){
		delete [] this->m_EmpArry;
		this->m_EmpArry = NULL;
	}
}

void WorkerManager::Show_Menu(){
	cout << endl;
	cout << "*****************************Welcome!****************************" << endl;
	cout << "0.exit 1.add 2.display 3.delete 4.medify 5.searh 6.sort 7.destroy" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem(){
	cout << "*****************************Goodbye!****************************" << endl;
	exit(0);
}

void WorkerManager::Add_Emp(){
	int addnum;
	cout << "Please input the number of inputing: ";
	cin >> addnum;
	if(addnum<=0){
		cout << "Error, addnum can not be negative!" << endl;
		return;
	}else{
		int newSize = this->m_EmpNum + addnum;
		Worker ** newspace = new Worker*[newSize];
		//copy the old
		if(this->m_EmpArry != NULL)
			for(int i=0; i<this->m_EmpNum; i++)
				newspace[i] = m_EmpArry[i];
		//add the new
		cout << "please input:" << endl << "ID\tNAME\tpersiotion(1.employee 2.manager 3.boss)" << endl;
		for(int i=m_EmpNum; i<newSize; i++){
			int id;
			string name;
			int dselect;
			point: cin >> id >> name >> dselect;
			Worker *w = NULL;
			switch(dselect){
				case 1:
					w = new Employee(id,name,dselect);
					break;
				case 2:
					w = new Manager(id,name,dselect);
					break;
				case 3:
					w = new Boss(id,name,dselect);
					break;
				default:
					cout << "this inpution error!\tinput this again" << endl;
					goto point;
					break;
			}	
			newspace[i] = w;
		}
		//delete old array
		delete [] this->m_EmpArry;
		this->m_EmpArry = newspace;
		this->m_EmpNum = newSize;
		cout << "add scucess! " << addnum << endl;
	}

}

void WorkerManager::save(){
	ofstream fout(FILENAME,ios::out);
	for(int i=0; i<this->m_EmpNum; i++){
		fout << this->m_EmpArry[i]->m_Id << " "
		     << this->m_EmpArry[i]->m_Name << " "
		     << this->m_EmpArry[i]->m_DeptId << endl;
	}
	fout.close();
	m_FileIsEmpty = false;
}

int WorkerManager::getFileNum(ifstream &fin){
	char buff[50];
	int num=0;
	while(fin.getline(buff,sizeof(buff)))	
		num++;
	return num;
}

void WorkerManager::init_Emp(int num){
	ifstream fin;
	fin.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	Worker *w;
	Worker **space = new Worker*[num];
	for(int i=0; i<num; i++){
		fin >> id >> name >> did;
		switch(did){
			case 1: w = new Employee(id,name,did);
				break;
			case 2: w = new Manager(id,name,did);
				break;
			case 3: w = new Boss(id,name,did);
				break;
			default:
				break;
		}
		space[i] = w;
	}
	this->m_EmpNum = num;
	this->m_EmpArry = space;
	this->m_FileIsEmpty = false;
}

void WorkerManager::show_Emp(){
	if(this->m_FileIsEmpty){
		cout << "-table is empty!" << endl;
		return;
	}
	for(int i=0; i<m_EmpNum; i++)
		m_EmpArry[i]->ShowInfo();
}

int WorkerManager::locate(int k){
	if(this->m_FileIsEmpty==true)
		return -1;
	for(int i=0; i<this->m_EmpNum; i++)
		if(this->m_EmpArry[i]->m_Id==k)
			return i;
	return -1;
}

void WorkerManager::Del_Emp(int k){
	int loc = this->locate(k);
	if(loc<0){
		cout << "worker " << k << " does not exit!" << endl;
		return;
	}
	delete this->m_EmpArry[loc];
	for(int i=loc; i<this->m_EmpNum-1; i++){
		this->m_EmpArry[i] = this->m_EmpArry[i+1];
	}
	this->m_EmpArry[m_EmpNum-1] = NULL;
	this->m_EmpNum--;
	if(m_EmpNum==0)
		m_FileIsEmpty = true;
	cout << "delete " << k << " ok!" << endl;
}
void WorkerManager::Medify_Emp(int k){
	int loc = this->locate(k);
	if(loc<0){
		cout << "worker " << k << " does not exit!" << endl;
		return;
	}
	int id; string name; int did;
	cout << "please input new infomation:" << endl << "ID\tNAME\tpersiotion(1.employee 2.manager 3.boss)" << endl;
	point : cin >> id >> name >> did;
	Worker *w;
	switch(did){
		case 1:	w = new Employee(id,name,did);
			break;
		case 2: w = new Manager(id,name,did);
			break;
		case 3: w = new Boss(id,name, did);
			break;
		default:
			cout << "input error! try again" << endl;
			goto point;
			break;
	}
	delete this->m_EmpArry[loc];
	this->m_EmpArry[loc] = w;
	cout << "medify ok!" << endl;
}
void WorkerManager::search_by_ID(int id){
	if(id<=0){
		cout << "id cannot be negative!" << endl;
		return;
	}
	for(int i=0; i<this->m_EmpNum; i++)
		if(id==this->m_EmpArry[i]->m_Id){
			this->m_EmpArry[i]->ShowInfo();
			return;
		}
	cout << "cannot find target!" << endl;
}

void WorkerManager::search_by_Name(string name){
	bool flage=false;
	for(int i=0; i<this->m_EmpNum; i++)
		if(name==this->m_EmpArry[i]->m_Name){
			this->m_EmpArry[i]->ShowInfo();
			flage = true;
		}
	if(!flage)
		cout << "cannot find target!" << endl;
}

void WorkerManager::Sort_by_ID(){
	if(this->m_EmpNum==0 || this->m_EmpNum==1 || this->m_FileIsEmpty==true){
		cout << "can not sort!" << endl;
		return;
	}
	Worker *tmp;
	int i,j;
	for(i=1; i<this->m_EmpNum; i++){
		if(this->m_EmpArry[i]->m_Id < this->m_EmpArry[i-1]->m_Id){
			tmp = this->m_EmpArry[i];
			for(j=i-1; j>0&&this->m_EmpArry[j]->m_Id>tmp->m_Id ;j--)
				this->m_EmpArry[j+1] = this->m_EmpArry[j];
			this->m_EmpArry[j+1] = tmp;
		}
	}
	cout << "sortted!" << endl;
}

void WorkerManager::Clean(){
	char ch='N';
	cout << "confirm to destroy: Y/N" << endl;
	cin >> ch;
	 if(ch!='Y'){
		cout << "cancel!" << endl;
		return;
	}
	if(ch=='Y'){
		cout << "kail" << endl;
		ofstream fout(FILENAME, ios::out);
		if(!fout){
			cout << "edmo" << endl;
		}
		fout.close();
		if(this->m_EmpArry!=NULL){
			for(int i=0; i<this->m_EmpNum; i++)
				if(this->m_EmpArry[i]!=NULL){
					delete this->m_EmpArry[i];
					this->m_EmpArry[i] = NULL;
				}
			this->m_EmpNum = 0;
			delete [] this->m_EmpArry;
			this->m_EmpArry = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "destroied!" << endl;
	}
}

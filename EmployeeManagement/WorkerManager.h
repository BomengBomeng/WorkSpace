#pragma once
#include<iostream>
#include"Worker.h"
#include<fstream>
using namespace std;

#define FILENAME "empfile.dat"

class WorkerManager{
public:
	WorkerManager();
	void Show_Menu();
	void ExitSystem();
	void Add_Emp();
	void save();
	int getFileNum(ifstream &fin);
	void init_Emp(int num);
	void show_Emp();
	int locate(int k);
	void Del_Emp(int k);
	void Medify_Emp(int k);
	void search_by_ID(int id);
	void search_by_Name(string name);
	void Sort_by_ID();
	void Clean();
	~WorkerManager();
public:
	int m_EmpNum;
	Worker** m_EmpArry;
	bool m_FileIsEmpty;
};

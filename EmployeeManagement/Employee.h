#pragma once
#include<iostream>
#include"Worker.h"
#include<string>
using namespace std;

class Employee : public Worker
{
public:
	Employee(int id, string name ,int deptid);
	virtual void ShowInfo();
	virtual string getDeptName();
};

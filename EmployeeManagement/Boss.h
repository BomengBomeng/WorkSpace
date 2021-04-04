#pragma once
#include<iostream>
#include"Worker.h"
#include<string>
using namespace std;

class Boss : public Worker
{
public:
	Boss(int id, string name ,int deptid);
	virtual void ShowInfo();
	virtual string getDeptName();
};

#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray{
public:
	MyArray(int capacity){
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[capacity];
	}
	MyArray(const MyArray &arr){
		this->m_capacity = arr->m_capacity;
		this->m_size = arr->m_size;
		this->pAddress = new T[this->m_capacity];
		for(int i=0; i<arr->m_size; i++)
			this->pAddress[i] = arr->pAddress[i];
	}
	MyArray& operator=(const MyArray &arr){
		if(this->pAddress!=NULL){
			delete [] this->pAddress;
			this->pAddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = arr->m_capacity;
		this->m_size = arr->m_size;
		this->pAddress = new T[this->m_capacity];
		for(int i=0; i<arr->m_size; i++)
			this->pAddress[i] = arr->pAddress[i];
		return *this;
	}
	void push_back(const T &val){
		if(this->m_capacity==this->m_size){
			cout << "Error Array is full!" << endl;
			return;	
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}
	void pop_back(){
		if(this->m_size==0){
			cout << "Error Array is empty!" << endl;
			return;
		}
		this->m_size--;
	}
	T& operator[](int index){
		return this->pAddress[index];
	}
	int get_capacity(){
		return this->m_capacity;
	}
	int get_size(){
		return this->m_size;
	}
	~MyArray(){
		if(this->pAddress!=NULL)
			delete [] this->pAddress;
		this->pAddress = NULL;
		this->m_capacity = 0;
		this->m_size = 0;
	}
private:
	T *pAddress;
	int m_capacity;
	int m_size;
};

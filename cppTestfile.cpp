#include<iostream>
#include<string>
using namespace std;

class CPU
{
public:
	virtual void calculate()=0;
};

class VideoCard
{
public:
	virtual void display()=0;
};

class Memory
{
public:
	virtual void storage()=0;
};

class intelCPU : public CPU
{
	void calculate(){
		cout << "intel cpu calcuylate" << endl;
	}
};
class intelVideoCard : public VideoCard
{
	void display(){
		cout << "intel videocard display" << endl;
	}
};
class intelMemory : public Memory
{
	void storage(){
		cout << "intel memory storage" << endl;
	}
};



class lenovolCPU : public CPU
{
	void calculate(){
		cout << "lenovo cpu calcuylate" << endl;
	}
};
class lenovoVideoCard : public VideoCard
{
	void display(){
		cout << "lenovo videocard display" << endl;
	}
};
class lenovolMemory : public Memory
{
	void storage(){
		cout << "lenovo memory storage" << endl;
	}
};



class computer
{
public:
	computer(CPU *cpu, VideoCard *vc, Memory *mem){
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	void work(){
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	~computer(){
		if(m_cpu!=NULL){
			delete m_cpu;
			m_cpu = NULL;
		}
		if(m_vc!=NULL){
			delete m_vc;
			m_vc = NULL;
		}
		if(m_mem!=NULL){
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU *m_cpu;
	VideoCard *m_vc;
	Memory *m_mem;
};

void test01(){
	CPU * intelcpu = new intelCPU;
	VideoCard *intelCard = new intelVideoCard;
	Memory * intelMem = new intelMemory;
	computer *comp1 = new computer(intelcpu,intelCard,intelMem);
	comp1->work();
	delete comp1;
	cout << "-----------------------------------------" << endl;
	computer *comp2 = new computer(new lenovolCPU, new intelVideoCard, new lenovolMemory);
	comp2->work();
	delete comp2;
}

int main(){
	test01();
	return 0;
}

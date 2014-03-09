#include <iostream>
#include <malloc.h>
#include <typeinfo>

using namespace std;


class A
{
	int a ;
	public:
	A()
	{
		cout<<"In A's constructor\n";
	}
	
	void * operator new (size_t bytes, const nothrow_t & e) throw()
	{
		cout<<"With nothrow\n";
		return malloc(bytes);
	}

	void * operator new (size_t bytes)
	{
		cout<<"Without nothrow\n";
		return malloc(bytes);
	}
	void print()
	{
		cout<<"Here\n";
	}
};

int main()
{
	int i =10;
	int * p = new int;
	int * p1 = new (nothrow) int;
	//A* p2 =  (A*)operator new(sizeof(A));
	cout<<"Before going into the constructor\n";
	//new (p2) A;	
	//cout<<typeid(*p2).name()<<endl;
	//p2->print();
	A * p2 = new (nothrow) A;
	cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
	//A * a = new (nothrow) A;
	//void * ptr = operator new(sizeof(A));
	//new (ptr) A;
	A * a = new(nothrow) A;
	A * a1 = new A;
	//cout<<"sizeof(*a1)= "<<sizeof(*a1)<<endl;
	return 0;
}

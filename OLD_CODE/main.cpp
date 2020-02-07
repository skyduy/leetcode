#include<iostream>
using namespace std;

class A {
public:
	A();
	A(int a);
	~A();
};

A::A() {
	cout << "cons with none" << endl;
}
A::A(int a) {
	cout << "cons with " << a << endl;
}
A::~A() {
	cout << "bye" << endl;
}


int main() {
	A a;
	a = A();
	A b = A(1);
	cout << " will dead " << endl;	
}

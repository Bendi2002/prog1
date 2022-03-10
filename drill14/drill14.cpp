#include "../std_lib_facilities.h"

class B1 {
public:
	virtual void vf(){
		cout << "B1::vf()\n";
	}
	void f(){
		cout << "B1::f()\n";
	}
	void pvf(){
		cout << "B1::pvf\n";
	}
};

class D1:public B1 {
public:
	virtual void vf(){
		cout << "D1::vf()\n";
	}
	void f(){
		cout << "This is f()\n";
	}
};

class D2:public D1 {
public:
	virtual void pvf(){
		cout << "D2 here, radio check\n";
	}
};

class D21:public B1 {
public:
	string text = "some random text\n";
	virtual void pvf(){
		cout << text;
	}
};

class D22:public B1 {
public:
	int num = 29;
	virtual void pvf(){
		cout << num << '\n';
	}
};

void f(B1& b1){
	b1.f();
	b1.vf();
	b1.pvf();
}

int main(){
	B1 b1;
	D1 d1;
	D2 d2;
	D21 d21;
	D22 d22;

	b1.f();
	b1.vf();
	d1.f();
	d1.vf();
	
	B1& bref = d1;

	bref.f();
	bref.vf();

	d2.f();
	d2.vf();
	d2.pvf();

	f(b1);
	f(d21);
	f(d22);

	return 0;
}
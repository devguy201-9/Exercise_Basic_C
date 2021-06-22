#include<iostream>
using namespace std;
class Animal {
public:
	virtual void move() {
		cout << "animal move...." << endl;
	}
};
class Bird:public Animal {
public:
	void move() override {
		cout << "it is fly..." << endl;
	}
};
class Dog :public Animal {
public:
	void move() override {
		cout << "it is go to the round...." << endl;
	}
};
int main()
{
	Animal* a = new Bird();
	a->move();
	a = new Dog();
	a->move();
	return 0;
}
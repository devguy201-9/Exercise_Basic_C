#include<iostream>
#include<string>
#include"Person.h"
using namespace std;
void getPersonInfo(Person* ps,size_t n) {
	int age;
	string first, mid, last, address, phone, gender;
	cout << "Enter infomation:" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << "first name: "; cin >> first;
		cout << "last name: "; cin >> last;
		cout << "middle name: ";
		cin.ignore();
		getline(cin, mid);
		cout << "address: "; cin.ignore();
		getline(cin, address);
		cout << "phonenumber: "; cin >> phone;
		cout << "gender: "; cin >> gender;
		cout << "Age: "; cin >> age;
		Person p(0, first, mid, last, age, address, gender,phone);
		ps[i] = p;
	}
}
void showinfo(Person* ps, size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		ps[i].showinfo();
	}
}

int main()
{
	Person* people;
	size_t n;
	cout << "Enter the number of people: ";
	cin >> n;
	people = new Person[n];
	getPersonInfo(people, n);
	showinfo(people, n);
	return 0;
}
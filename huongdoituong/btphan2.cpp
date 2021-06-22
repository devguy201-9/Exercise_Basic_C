#include<iostream>
#include"employee.h"
void getEmployeeInfo(employee* emp, size_t n) {
	long salary,add;
	string name, address, cv, phoneNumber;
	cout << "Enter Infomation" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << "full name: "; cin.ignore();
		getline(cin, name);
		cout << "position: "; cin.ignore();
		getline(cin, cv);
		cout << "address: "; cin.ignore();
		getline(cin, address);
		cout << "salary: "; cin >> salary;
		cout << "raisesalary: "; cin >> add;
		cout << "phonenumber: "; cin >> phoneNumber;
		employee temp(0, name, address, cv, phoneNumber, salary);
		emp[i] = temp;
		emp[i].raiseSalary(add);
	}
}
void hoanvi(employee& a, employee& b) {
	employee temp = a;
	a = b;
	b = temp;
}
void shortsalary(employee* emp, size_t n) {
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = i+1; j < n; j++)
		{
			long temp1 = emp[i].getSalary();
			long temp2 = emp[j].getSalary();
			if (temp1 < temp2)
				hoanvi(emp[i], emp[j]);
		}
	}
}
void showInfomation(employee* emp,size_t n) {
	shortsalary(emp, n);
	for (size_t i = 0; i < n; i++)
	{
		emp[i].showInfo();
	}
}
int main()
{
	employee* emp;
	size_t n;
	cout << "Enter the number employee: "; cin >> n;
	emp = new employee[n];
	getEmployeeInfo(emp, n);
	showInfomation(emp, n);
	return 0;
}
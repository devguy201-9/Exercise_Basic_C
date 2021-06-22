#pragma once
#include<string>
using namespace std;
class employee
{
private:
	int ma;
	string name;
	string address;
	string cv;
	string phoneNumber;
	long salary;
public:
	static int id;
	employee();
	employee(int, string, string, string, string, long);
	void setID(int);
	int getID();
	void setName(string);
	string getName();
	void setAddress(string);
	string getAddress();
	void setCv(string);
	string getCv();
	void setPhoneNumber(string);
	string getPhoneNumber();
	void setSalary(long);
	long getSalary();

	void raiseSalary(long);
	void showInfo();
};


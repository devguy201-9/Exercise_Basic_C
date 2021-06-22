#pragma once
#include<string>
using namespace std;
class Person {
private:
	int ma;
	string firstName;
	string midName;
	string lastName;
	int tuoi;
	string gender;
	string address;
	string phoneNumber;
public:
	Person();
	static int id;
	Person(int, string, string, string, int, string, string, string);
	void setID(int);
	int getID();
	void setAge(int);
	int getAge();
	void setFirstName(string);
	string getFirstName();
	void setMidName(string);
	string getMidName();
	void setLastName(string);
	string getLastName();
	void setGender(string);
	string getGender();
	void setAddress(string);
	string getAddress();
	void setPhoneNumber(string);
	string getPhoneNumber();

	void showinfo();
	string fullname();
};
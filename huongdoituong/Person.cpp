#include "Person.h"
#include<iostream>
Person::Person() {
	this->ma = 0;
	this->firstName = "";
	this->midName = "";
	this->lastName = "";
	this->tuoi = 0;
	this->gender = "";
	this->address = "";
	this->phoneNumber = "";
}
Person::Person(int id, string firstName, string midName,
	string lastName, int age, string address, string gender, string phoneNumber) {
	setID(id);
	setAge(age);
	setFirstName(firstName);
	setMidName(midName);
	setLastName(lastName);
	setGender(gender);
	setAddress(address);
	setPhoneNumber(phoneNumber);
}
int Person::id = 100;
void Person::setID(int id) {
	this->ma = (id >= 100) ? id : Person::id++;
}
void Person::setAge(int age) {
	this->tuoi = (age >= 0) ? age : 0;
}
void Person::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Person::setMidName(string midName) {
	this->midName = midName;
}
void Person::setLastName(string lastName) {
	this->lastName = lastName;
}
void Person::setGender(string gender) {
	this->gender = gender;
}
void Person::setAddress(string address) {
	this->address = address;
}
void Person::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

int Person::getID() {
	return this->ma;
}
int Person::getAge() {
	return this->tuoi;
}
string Person::getFirstName() {
	return this->firstName;
}
string Person::getMidName() {
	return this->midName;
}
string Person::getLastName() {
	return this->lastName;
}
string Person::getGender() {
	return this->gender;
}
string Person::getAddress() {
	return this->address;
}
string Person::getPhoneNumber() {
	return this->phoneNumber;
}
void Person::showinfo() {
	cout << "================ Person info ===========" << endl
		 << "ma: " << getID() << endl
		 << "ho: " << getFirstName() << endl
		 << "dem: " << getMidName() << endl
	   	 << "ten: " << getLastName() << endl
		 <<"ho va ten: "<<fullname()<<endl
		 << "tuoi: " << getAge() << endl
		 << "gioi tinh: " << getGender() << endl
		 << "dia chi: " << getAddress() << endl
		 << "so dien thoai: " << getPhoneNumber() << endl
		 << "========================================" << endl;
}
string Person::fullname() {
	return getFirstName() + " " + getMidName() + " " + getLastName();
}
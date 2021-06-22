#include "employee.h"
#include<iostream>
employee::employee() {
	this->ma = 0;
	this->name = "";
	this->address = "";
	this->cv = "";
	this->phoneNumber = "";
	this->salary = 0;
}
int employee::id = 1000;
employee::employee(int id, string name, string address,
	string cv, string phonenumber, long luong) {
	setID(id);
	setName(name);
	setAddress(address);
	setCv(cv);
	setPhoneNumber(phonenumber);
	setSalary(luong);
}
void employee::setID(int id) {
	this->ma = (id >= 1000) ? id : employee::id++;
}
int employee::getID() {
	return this->ma;
}
void employee::setName(string name) {
	this->name = name;
}
string employee::getName() {
	return this->name;
}
void employee::setAddress(string address) {
	this->address = address;
}
string employee::getAddress() {
	return this->address;
}
void employee::setCv(string cv) {
	this->cv = cv;
}
string employee::getCv() {
	return this->cv;
}
void employee::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}
string employee::getPhoneNumber() {
	return this->phoneNumber;
}
void employee::setSalary(long salary) {
	this->salary = salary;
}
long employee::getSalary() {
	return this->salary;
}
void employee::raiseSalary(long amount) {
	this->salary += amount;
}
void employee::showInfo() {
	cout << "================== Employee Info ===========" << endl
		<< "ma: " << getID() << endl
		<< "ho va ten: " << getName() << endl
		<< "dia chi: " << getAddress() << endl
		<< "chuc vu: " << getCv() << endl
		<< "tien luong: " << getSalary() << endl
		<< "so dien thoai: " << getPhoneNumber() << endl
	 	<< "============================================" << endl;
}
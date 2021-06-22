#include<iostream>
#include<cstring>
using namespace std;
class Student {
private:
	char ID[20];
	int age;
	float diem;
	char name[100];
	char address[100];

	static int count;
public:
	Student();
	Student(char*);
	void showinfo();

	void setID(char*);
	void setName(char*);
	void setAge(int);
	void setDiem(float);
	void setAddress(char*);

	char* getID();
	int getAge();
	float getDiem();
	char* getname();
	char* getAddress();

	//static int count;

	static int getCount();
};
int Student::count = 0;

int Student:: getCount() {
	return Student::count;
}
Student::Student() {
	cout << "ham tao mac dinh" << endl;
	this->ID[0] = '\0';
	this->age = 0;
	this->diem = 0;
	this->name[0] = '\0';
	this->address[0] = '\0';
	count++;
}
Student::Student(char* name) {
	cout << "ham tao mac dinh 1" << endl;
	strcpy_s(this->name, 99, name);
	this->ID[0] = '\0';
	this->age = 0;
	this->diem = 0;
	this->address[0] = '\0';
	count++;
}
void Student::showinfo() {
	cout << "===================info student==============" << endl;
	cout << "id: " << ID << endl;
	cout << "name: " << name << endl;
	cout << "diem: " << diem << endl;
	cout << "tuoi: " << age << endl;
	cout << "dia chi: " << address << endl;
	cout << "=============================================" << endl;
}
void Student:: setID(char* id){
	strcpy_s(this->ID, 20, id);
}
void Student::setName(char* name){
	strcpy_s(this->name, 99, name);
}
void Student::setAge(int tuoi) {
	this->age = tuoi;
}
void Student::setDiem(float diem) {
	this->diem = diem;
}
void Student::setAddress(char* diachi) {
	strcpy_s(this->address, 99, diachi);
}

char* Student:: getID() {
	return this->ID;
}
int Student::getAge() {
	return this->age;
}
float Student::getDiem() {
	return this->diem;
}
char* Student::getname() {
	return this->name;
}
char* Student::getAddress() {
	return this->address;
}
int main()
{
	char* name =new char[100];
	strcpy_s(name, 99, "tran gia thuan");
	Student s;		//goi ham tao mac dinh 1
	Student s2(name);		//goi ham tao mac dinh 2
	s.showinfo();
	s2.showinfo();
	s.setAge(39);
	s.setName(name);
	cout << "tuoi: " << s.getAge() << endl;
	s.showinfo();
	s2.showinfo();

	//cout << s.count << endl;
	//cout << Student::count << endl;

	cout << s.getCount() << endl;
	cout << Student::getCount() << endl;
	return 0;
}
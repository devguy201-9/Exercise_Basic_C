#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Person {
private:
	int age;
	string name;
	string address;
public:
	Person();
	Person(int, string, string);
	friend void writeToFile(Person, fstream&);
};
Person::Person() {
	this->age = 0;
	this->name = "";
	this->address = "";
}
Person ::Person(int age, string name, string address) {
	this->age = age;
	this->name = name;
	this->address = address;
}
void writeToFile(Person ps, fstream& fpp) {
	fpp << ps.age << endl;
	fpp << ps.name << endl;
	fpp << ps.address << endl;
}
int main()
{
	fstream fpp("321.txt", ios::app);		//out:xoa info cu va ghi moi	app:ghi them vao
	//string mail = "infomation....";
	//fpp << mail << endl;
	Person a(19, "tran gia thuan", "tp ho chi minh");
	writeToFile(a, fpp);
	fpp.close();
	return 0;
}
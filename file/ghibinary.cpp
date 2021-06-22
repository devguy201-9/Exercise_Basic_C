#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Person1 {
private:
	int age;
	char name[100];
	char adress[100];
public:
	Person1();
	Person1(int, string, string);
	friend void writeBinary(Person1, ofstream&);
	void setAge(int);
	void setName(string);
	void setAddress(string);
	void showInfo();
};
Person1::Person1() {
	this->age = 0;
	this->name[0] = '\0';
	this->adress[0] = '\0';
}
Person1::Person1(int age, string name, string address) {
	this->setAge(age);
	this->setName(name);
	this->setAddress(address);
}
void writeBinary(Person1 ps, ofstream& fpp) {
	if (fpp.good()) {
		fpp.write((char*)& ps, sizeof(Person1));
	}
}
void Person1::setAge(int age) {
	this->age = (age < 0) ? 0 : age;
}
void Person1:: setName(string name) {
	size_t size = name.length();
	size = (size > 99) ? 99 : size;
	name.copy(this->name, size);
	this->name[size] = '\0';		
}
void Person1:: setAddress(string address) {
	size_t size = address.length();
	size = (size > 99) ? 99 : size;
	address.copy(this->adress, size);
	this->adress[size] = '\0';	//co the bi loi tran bo dem		this->adress[size] = '\0';
}
void Person1:: showInfo() {
	cout << "tuoi: " << age << ";ho va ten: " << name << ";dia chi: " << adress << endl;
}
int main()
{
	Person1 s(13, "gsfhshd dgf", "ben tre");
	Person1 s1(15, "vf sd dg", "tp ho chi minh");
	Person1 s2(19, "tran gia thuan", "tp ho chi minh");
	ofstream fp("filebinaryabc.bat",ios::binary);
	writeBinary(s, fp);
	writeBinary(s1, fp);
	writeBinary(s2, fp);
	fp.close();

	//DOC FILE BINARY

	ifstream fpp("filebinaryabc.bat", ios::binary);
	Person1 a;
	if (!fpp) {
		cout << "loi du lieu" << endl;
	}
	else {
		int index;
		cout << "nhap vi tri muon doc: "; cin >> index;
		index = (index >= 0 && index <= 2) ? index : 0;
		fpp.seekg(index * sizeof(Person1));
		fpp.read((char*)&a, sizeof(Person1));
		if (fpp.good()) {
			a.showInfo();
		}
		/*while (!fpp.eof())
		{
			fpp.read((char*)&a, sizeof(Person1));
			if (fpp.good())
			{
				a.showInfo();
			}
		}*/
	}
	return 0;
}
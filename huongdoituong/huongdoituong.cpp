#include<iostream>
using namespace std;
class Nguoi
{
protected:
	string ten;
	int tuoi;
public:
	Nguoi()
	{
		tuoi = 18;
		ten = "tran gia thuan";
	}
	virtual void hama()		//danh dau ham ao
	{
		cout << "truy cap dc vao ham" << endl;
	}
};
class SinhVien:public Nguoi
{
	string msv;
public :
	SinhVien()
	{
		msv = "3119410418";
	}
	void xuat()
	{
		cout << "thong tin: msv: " << msv << ", ten: " << ten << ", tuoi: " << tuoi << endl;
	}
	void hama()
	{
		cout << "truy cap dc vao ham ;" << endl;
	}
};
class Moi
{
private:
	int a, b;
	string c;
public:
	Moi()
	{
		a = 6;
		b = 14;
		c = "lap trinh huong doi tuong";
	}
	friend int cong(Moi a, Moi b);
};
int cong(Moi a, Moi b)
{
	return a.a + b.b;
}
int main()
{
	Moi a, b;
	SinhVien n;
	cout << "tong cua 2 so la: " << cong(a, b)<<endl;
	n.xuat();
	n.hama();
	return 0;
}
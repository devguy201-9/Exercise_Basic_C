#include<iostream>
#include<iomanip>
#define max 50
using namespace std;
typedef struct Date {
	int day;
	int month;
	int year;
};
typedef struct Canbo {
	char ma[10];
	char hoten[20];
	Date ngaysinh;
	char gioitinh[5];
	char dang[6];
	int bacluong;
};
void nhapcanbo(Canbo a[], int &n) {
	cout << "nhap so luong cb can luu:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap ma so cb:"; cin >> a[i].ma;
		cout << "nhap ho ten cb:";
		cin.ignore(32767, '\n');
		gets_s(a[i].hoten);
		cout << "nhap ngay thang nam sinh:" << endl;
		cin >> a[i].ngaysinh.day >> a[i].ngaysinh.month >> a[i].ngaysinh.year;
		cout << "nhap gioi tinh:"; cin >> a[i].gioitinh;
		cout << "co la doan vien hay khong?" << endl;
		cin >> a[i].dang;
		cout << "nhap cap bac luong cua cb:"; cin >> a[i].bacluong;
	}
}
void xuatcb(Canbo a[], int n)
{
	cout << "				THONG TIN TAT CA CB" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << a[i].ma << setw(5) << a[i].hoten << setw(5) <<
			a[i].ngaysinh.day << '/' << a[i].ngaysinh.month << '/' << a[i].ngaysinh.year <<
			setw(5) << a[i].gioitinh << setw(5) << a[i].dang << setw(5) << a[i].bacluong << endl;
	}
}
void hoanvi(Canbo& a, Canbo& b)
{
	Canbo temp = a;
	a = b;
	b = temp;
}
//theo chu cai
void sapxep(Canbo a[], int n)
{
	for (int i = 0; i < n; i++)
	{

	}
}
int main()
{
	int n;
	Canbo a[max];
	nhapcanbo(a, n);
	xuatcb(a, n);
	return 0;
}
#include<iostream>
#include<math.h>
#include<cstring>
#define max 50
using namespace std;
struct sinhvien
{
	char msv[max];
	char hoten[max];
	int ngay,thang,nam;
	float toan, ly, hoa, dtb;
};
void nhapsinhvien(sinhvien a[], int n);
void xuatsinhvien(sinhvien a[], int n);
void maxdtb(sinhvien a[], int n);
void svtheodtbtang(sinhvien a[], int n);
void svtheotoangiam(sinhvien a[], int n);
void timsvdudk(sinhvien a[], int n);
void timmaxtuoi(sinhvien a[], int n);
int main()
{
	int n;
	sinhvien a[max];
	cout << "nhap so luong sinh vien: ";
	cin >> n;
	nhapsinhvien(a, n);
	xuatsinhvien(a, n);
	maxdtb(a, n);	
	svtheodtbtang(a, n);
	cout << "		danh sach sinh vien sau khi sap xep tang theo dtb" << endl;
	cout << endl;
	xuatsinhvien(a, n);
	timsvdudk(a, n);
	timmaxtuoi(a, n);
	return 0;
}
void nhapsinhvien(sinhvien a[], int n)
{
	float tam;
	cout << "nhap danh sach sinh vien: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin.ignore(32767, '\n');
		cout << "nhap msv: "; fflush(stdin);
		gets_s(a[i].msv);
		cout << "nhap ho ten: "; fflush(stdin);
		gets_s(a[i].hoten);
		cout << "nhap ngay sinh: "; cin >> a[i].ngay;
		cout << "nhap thang sinh: "; cin >> a[i].thang;
		cout << "nhap nam sinh: "; cin >> a[i].nam;
		cout << "nhap diem toan: "; cin >> a[i].toan;
		cout << "nhap diem ly: "; cin >> a[i].ly;
		cout << "nhap diem hoa: "; cin >> a[i].hoa;
		tam = a[i].toan + a[i].hoa + a[i].ly;
		a[i].dtb =1.0*tam / 3;
		cout << endl;
	}
}
void xuatsinhvien(sinhvien a[], int n)
{
	cout << "				danh sach sinh vien: ";
	cout << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "msv thu " << i << " la: " << a[i].msv;
		cout << endl;
		cout << "ho ten sv thu " << i << " la: " << a[i].hoten;
		cout << endl;
		cout << "ngay thang nam sinh cua sinh vien thu " << i << " la: " << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam;
		cout << endl;
		cout << "diem toan cua sinh vien thu " << i << " la: " << a[i].toan;
		cout << endl;
		cout << "diem ly cua sinh vien thu " << i << " la: " << a[i].ly;
		cout << endl;
		cout << "diem hoa cua sinh vien thu " << i << " la: " << a[i].hoa;
		cout << endl << endl;
	}
}
void maxdtb(sinhvien a[], int n)
{
	float max1 = 0;
	int tam = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].dtb > max1)
			max1 = a[i].dtb;
	}
	cout << "sinh vien co dtb cao nhat:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i].dtb == max1)
		{
			cout << "sinh vien co mssv: " << a[i].msv << endl;
			cout << "sinh vien co ho ten la: " << a[i].hoten << endl;
			cout << "ngay thang nam sinh cua sinh vien la: "<< a[i].ngay << "/" << a[i].thang << "/" << a[i].nam;
			cout << endl;
			cout << "diem toan sinh vien la: " << a[i].toan<<endl;
			cout << "diem ly cua sinh vien la: " << a[i].ly<<endl;
			cout << "diem hoa cua sinh vien la: " << a[i].hoa<<endl;
			cout << "dtb cua sinh vien la: " << a[i].hoa << endl<<endl;
		}
	}
	cout << endl;
}
void svtheodtbtang(sinhvien a[], int n)
{
	sinhvien b;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].dtb > a[j].dtb)
			{
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
	}
}
void svtheotoangiam(sinhvien a[], int n)
{
	sinhvien b;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].toan < a[j].toan)
			{
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
	}
}
void timsvdudk(sinhvien a[], int n)
{
	cout << "cac sinh vien co dtb > 5 va k co mon nao duoi 3" << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i].dtb > 5 && a[i].toan > 3 && a[i].ly > 3 && a[i].hoa > 3)
		{
			cout << "sinh vien co mssv: " << a[i].msv << endl;
			cout << "sinh vien co ho ten la: " << a[i].hoten << endl;
			cout << "ngay thang nam sinh cua sinh vien la: " << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam;
			cout << endl;
			cout << "diem toan sinh vien la: " << a[i].toan << endl;
			cout << "diem ly cua sinh vien la: " << a[i].ly << endl;
			cout << "diem hoa cua sinh vien la: " << a[i].hoa << endl;
			cout << "dtb cua sinh vien la: " << a[i].hoa << endl << endl;
		}
	}
}
int tuoimax(sinhvien a[], int n)
{
	int maxyear=0,tam;
	for (int i = 0; i < n ; i++)
	{
		tam = 2019 - a[i].nam;
		if (tam > maxyear)
			maxyear = tam;
	}
	return maxyear;
}
void timmaxtuoi(sinhvien a[], int n)
{
	int tam;
	cout << "sinh vien co tuoi lon nhat la:" << endl;
	for (int i = 0; i < n; i++)
	{
		tam = 2019 - a[i].nam;
		if (tuoimax(a, n) == tam)
		{
			cout << "sinh vien co mssv: " << a[i].msv << endl;
			cout << "sinh vien co ho ten la: " << a[i].hoten << endl;
			cout << "ngay thang nam sinh cua sinh vien la: " << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam;
			cout << endl;
			cout << "diem toan sinh vien la: " << a[i].toan << endl;
			cout << "diem ly cua sinh vien la: " << a[i].ly << endl;
			cout << "diem hoa cua sinh vien la: " << a[i].hoa << endl;
			cout << "dtb cua sinh vien la: " << a[i].hoa << endl << endl;
		}
	}
}
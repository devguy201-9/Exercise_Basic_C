#include<iostream>
#include<math.h>
#define max 100
using namespace std;
void nhapmang(int a[], int n);
void xuatmang(int a[], int n);
void caua(int a[], int n);		//4 11 10 7 101 8 5 16 3
void caub(int a[], int n, int m);
void toadohinh(int x1, int y1, int x2, int y2, int x3, int y3);
int main()
{
	int n,m,a[max];
	int x1, x2, x3, y1, y2, y3;
	//cout << "nhap so phan tu cua mang: "; cin >> n;
	//nhapmang(a, n);
	//caua(a, n);
	//xuatmang(a, n);
	//cout << "nhap so m de tim cap so tong: "; cin >> m;
	//caub(a, n, m);
	cout << "nhap toa do diem A:" << endl;
	cout << "nhap x: "; cin >> x1;
	cout << "nhap y: "; cin >> y1;
	cout << "nhap toa do diem B:" << endl;
	cout << "nhap x: "; cin >> x2;
	cout << "nhap y: "; cin >> y2;
	cout << "nhap toa do diem M de kiem tra diem co thuoc hcn duoc tao tu 2 diem A,B hay khong:" << endl;
	cout << "nhap x: "; cin >> x3;
	cout << "nhap y: "; cin >> y3;
	toadohinh(x1, y1, x2, y2, x3, y3);
	return 0;
}
void nhapmang(int a[], int n)
{
	cout << "nhap mang" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int checknt(int x)
{
	if (x < 2) return 0;
	int k = sqrt(x);
	for (int i = 2; i <= k; i++)
		if (x % i == 0) return 0;
	return 1;
}
void hoanvi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void caua(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((checknt(a[i]) == 1 && checknt(a[j]) == 1) && (a[i]>a[j]))
			{
				hoanvi(a[i], a[j]);
			}
		}
	}
}
void caub(int a[], int n,int m)
{
	cout << "nhung cap so co tong bang " << m << " trong day la:" << endl;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] + a[j] == m)
			{
				cout << a[i] << " " << a[j] << endl;
			}
}
int checkdiem(int x,int y,int z)
{
	for (int i = x; i <= y; i++)
		if (z == i)
			return 1;
	return 0;
}
void toadohinh(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if (checkdiem(x1, x2, x3) && (checkdiem(y1, y2, y3)))
		cout << "(" << x3 << "," << y3 <<  ") la diem thuoc hinh chu nhat tao duoc tu hai diem A,B" << endl;
	else
		cout << "(" << x3 << "," << y3 << ") khong la diem thuoc hinh chu nhat duoc tao tu hai diem A,B" << endl;
}
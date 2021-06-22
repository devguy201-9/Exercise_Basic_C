#include<iostream>
#define max 100
using namespace std;
void nhapmang(int a[], int n)
{
	cout << "nhap mang:"<<endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void inmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << "	" << a[i];
	cout << endl;
}
int ucln(int a, int b)		//de qui
{
	if (a == 0 && b == 0) return 0;
	if (a == 0) return b;
	if (b == 0) return a;
	return ucln(b, a % b);
}
//uoc so chung cua 3 so
int ucln3(int a, int b, int c)
{
	int x = ucln(a, b);
	return ucln(x, c);
}
int main()
{
	int a[max], n;
	cout << ucln(6, 9) << endl;
	cout << ucln3(16, 8, 12);
}
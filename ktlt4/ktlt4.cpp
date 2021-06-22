#include<iostream>
using namespace std;
//6 1 0 5 -5 1 15 3 3 10
void nhapmang(int* a, int n)
{
	cout << "nhap mang: " << endl;
	for (int i = 0; i < n; i++)
		cin >> *(a + i);
}
void xuatmang(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << " ";
	cout << endl;
}
void xoavtk(int* &a, int& n, int k)
{
	for (int i = k; i < n - 1; i++)
		*(a + i) = *(a + i + 1);
	n--;
	a = (int*)realloc(a, (n) * sizeof(int));
}
void themvtk(int* &a, int& n, int x, int vt)
{
	n++;
	a = (int*)realloc(a, n * sizeof(int));
	for (int i = n - 1; i > vt; i--)
		*(a + i) = *(a + i - 1);
	*(a + vt) = x;
}
int timmax(int* a, int n)
{
	int max = *a;
	for (int i = 1; i < n; i++)
		if (*(a + i) > max)
			max = *(a + i);
	return max;
}
int main()
{
	int n, * a;
	int k1,k2,x;
	cout << "nhap n: "; cin >> n;
	a = new int[n];
	nhapmang(a, n);
	cout << "cau a: " << timmax(a, n) << endl;
	cin >> k1;
	xoavtk(a, n, k1);
	cout << "cau b: ";
	xuatmang(a,n);
	cin >> k2;
	cin >> x;
	themvtk(a, n, x, k2);
	cout << "cau c: ";
	xuatmang(a, n);
	delete a;
	return 0;
}
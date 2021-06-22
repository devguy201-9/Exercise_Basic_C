#include<iostream>
using namespace std;
void nhapmang(int a[], int n) {
	cout << "nhap so phan tu cua mang: " << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void xuatmang(int a[], int n) {
	cout << "mang la: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void hoanvi(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void sapxep(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				hoanvi(a[i], a[j]);
}
int tich3max(int a[], int n, int& b, int& c, int& d) {
	int tich,max;
	tich = max = a[0] * a[1] * a[2];
	tich = a[n - 1] * a[n - 2] * a[0];
	if (tich > max)
	{
		max = tich;
		b = a[n - 1];
		c = a[n - 2];
		d = a[0];
	}
	else
	{
		b = a[0];
		c = a[1];
		d = a[2];
	}
	return max;
}
int main()
{
	int a[100];
	int n, so1, so2, so3;
	cout << "nhap n: "; cin >> n;
	nhapmang(a, n);
	xuatmang(a, n);
	sapxep(a, n);
	cout << "tich 3 so lon nhat la: " <<
		tich3max(a, n, so1, so2, so3) << endl;
	cout << "ba so: " << so1 << "," << so2 << "," << so3;
	return 0;
}
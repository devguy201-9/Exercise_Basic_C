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
void hoanvimang(int a[], int n, int k,int temp) {
	for (int i = 0; i < n-1; i++)
	{
		if (i < (n - k - 1))
			a[i] = a[i + 1];
		else
		{
			a[n - k - 1] = temp;
			break;
		}
	}
}
void chuyenmang(int a[], int n, int k) {
	int tam = k;
	while (true)
	{
		int temp = a[n - tam];
		a[n - tam] = a[0];
		hoanvimang(a, n, k, temp);
		tam--;
		if (tam < 1)
			break;
	}
}
int main()
{
	int a[100];
	int n,k;
	cout << "nhap n: "; cin >> n;
	nhapmang(a, n);
	xuatmang(a, n);
	cout << "nhap so phan tu can chuyen: "; cin >> k;
	chuyenmang(a, n, k);
	xuatmang(a, n);
	return 0;
}
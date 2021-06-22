#include<iostream>
using namespace std;
#define maxn 100
void nhapmang(int a[], int n);
void quicksort(int a[], int l, int r);
int main()
{
	int n, a[maxn];
	cout << "nhap n: "; cin >> n;
	nhapmang(a, n);
	quicksort(a, 0, n - 1);
	cout << a[n - 1];
	return 0;
}
void nhapmang(int a[], int n)
{
	cout << "nhap mang:" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void quicksort(int a[], int l, int r)
{
	int x = a[(l + r) / 2];
	int i = l;
	int j = r;
	do
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
			swap(a[i++], a[j--]);
	} while (i<j);
	if (l < j) quicksort(a, l, j);
	if (i < r) quicksort(a, i, r);
}
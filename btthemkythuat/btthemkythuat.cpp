#include<iostream>
using namespace std;
void xoak(int a[], int& n, int k) {
	if (k < 0 || k >= n) return;
	for (int i = k + 1; i < n; i++)
		a[i - 1] = a[i];
	n--;
}
//xoa trung
void xoaalltrung(int a[], int& n) {
	bool trung;
	for (int i = 0; i < n-1; i++)
	{
		trung = false;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j]) {
				trung = true;
				xoak(a, n, j--);
			}
		}
		if (trung == true)
			xoak(a, n, i--);
	}
}
int main()
{
	int a[10] = { 1,4,6,7,1,4,4,9 };
	int n = 8;
	xoaalltrung(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
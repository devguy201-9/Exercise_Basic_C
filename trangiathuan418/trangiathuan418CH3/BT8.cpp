#include<iostream>
using namespace std;
#define maxn 100
void nhapmang(int a[], int n);
int tim(int a[], int n, int x);
void quicksort(int a[], int l, int r);
int main()
{
	int n, a[maxn],b[maxn];
	cout << "nhap n: "; cin >> n;
	nhapmang(a, n);
	for (int i = 1; i <= n; i++)	//copy qua mang b
		b[i] = a[i];
	quicksort(a, 1, n);
	for(int i=n;i>=1;i--)
		if (tim(b, n, a[1]) < tim(b, n, a[i]))		//check vi tri
		{
			cout << a[i] - a[1];
			break;
		}
	return 0;
}
void nhapmang(int a[], int n)
{
	cout << "nhap mang:" << endl;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
int tim(int a[],int n, int x)
{
	int vt = 1;
	for(int i=1;i<=n;i++)
		if (a[i] == x)
		{
			vt = i;
			break;
		}
	return vt;
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
	} while (i < j);
	if (l < j) quicksort(a, l, j);
	if (i < r) quicksort(a, i, r);
}

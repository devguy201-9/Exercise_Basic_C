#include<iostream>
#define maxn 1000001
using namespace std;
void hoanvi(int& a, int& b)
{
	int temp = a; a = b; b = temp;
}
void quicksort(int a[], int l,int r)
{
	int x = a[(l + r) / 2];
	int i = l;
	int j = r;
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
			hoanvi(a[i++], a[j--]);
	} while (i < j);
	if (l < j) quicksort(a, l, j);
	if (i < r) quicksort(a, i, r);
}
long long tich3max(int a[], int n) {
	quicksort(a, 0, n-1);
	long long tich, max;
	max =(long long)a[n-1] * a[n-2] * a[n-3];
	tich = (long long)a[0] * a[1] * a[n-1];
	if (tich > max) max = tich;
	return max;
}
void docfile(int a[], int& n)
{
	FILE* f=fopen("VD3.INP", "rt");
	if (!f)
	{
		cout << "khong mo duoc file f";
		return;
	}
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}
void ghiketqua(int a[], int n)
{
	FILE* f=fopen("VD3.OUT", "wt");
	fprintf(f, "%lld ", tich3max(a,n));
	fclose(f);
}
int main()
{
	int n;
	int* a;
	a = new int[maxn];
	docfile(a, n);
	ghiketqua(a, n);
	delete a;
	return 0;
}

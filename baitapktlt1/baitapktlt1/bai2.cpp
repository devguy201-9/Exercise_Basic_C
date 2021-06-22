#include<iostream>
using namespace std;
#define MAX 100000
void docfile(int a[], int& n);
void ghifile(int a[], int n);
void timmax123(int a[], int n);
int mangconmax(int a[], int n);
FILE *g;
int main()
{
	int a[MAX], n;
	docfile(a, n);
	ghifile(a, n);
	return 0;
}
void docfile(int a[], int& n)
{
	FILE* f;
	fopen_s(&f, "songuyen.inp", "rt");
	if (!f)
	{
		cout << "khong mo duoc file f";
		return;
	}
	fscanf_s(f, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf_s(f, "%d", &a[i]);
	fclose(f);
}
void ghifile(int a[], int n){
	fopen_s(&g, "ketqua.out", "wt");
	timmax123(a, n);
	fprintf(g, "%d", mangconmax(a, n));
	fclose(g);
}
void timmax123(int a[], int n)
{
	int max1, max2, max3;
	max1 = max2 = max3 = -10000;
	for (int i = 0; i < n; i++)
		if (a[i] > max1)
			max1 = a[i];
	for (int i = 0; i < n; i++)
		if (a[i] > max2 && a[i] < max1)
			max2 = a[i];
	for (int i = 0; i < n; i++)
		if (a[i] > max3 && a[i] < max2)
			max3 = a[i];
	fprintf(g, "%d %d %d\n", max1, max2, max3);
}
int mangconmax(int a[], int n) {
	int max = INT32_MIN;
	for (int i = 0; i < n - 1; i++)
	{
		int dem = 1;
		int temp = a[i];
		for (int j = i + 1; j < n; j++)
		{
			if (temp < a[j])
			{
				temp = a[j];
				dem++;
			}
			else if (temp > a[j])
				break;
		}
		if (dem > max)
			max = dem;
	}
	return max;
}
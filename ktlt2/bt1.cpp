#include<iostream>
#define maxn 1000001
using namespace std;
int chieudai(int a[], int n)
{
	int dem = 1;
	int max = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] <= a[i + 1])
			dem++;
		else
		{
			if (dem > max)
				max = dem;
			dem = 1;
		}
		if (i == (n - 2))
		{
			if (dem > max)
				max = dem;
		}
	}
	return max;
}
void docfile(int a[], int& n, int& k)
{
	FILE* f;
	fopen_s(&f, "BT1.INP", "rt");
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
void ghiketqua(int a[], int n, int k)
{
	FILE* f;
	fopen_s(&f, "BT1.OUT", "wt");
	fprintf(f, "%d", chieudai(a, n));
	fclose(f);
}
int main()
{
	int n, k;
	int* a;
	a = new int[maxn];
	docfile(a, n, k);
	ghiketqua(a, n, k);
	return 0;
}
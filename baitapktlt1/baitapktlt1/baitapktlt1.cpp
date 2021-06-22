#include<iostream>
#include<stdio.h>
#include<math.h>
#define MAX 30000
using namespace std;
void docfile(int a[], int& n);
void ghifile(int a[], int n);
int capsntcungnhau(int a[], int n);
void demxuathien(int a[], int n);
int ntdx(int a[], int n);
int tongbiendoi(int a[], int n);
int mangconmax(int a[], int n);
int kcmax(int a[], int n);
FILE* g;
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
	fopen_s(&f, "NUM.INP", "rt");
	if (!f)
	{
		cout << "khong mo duoc file f";
		return;
	}
	fscanf_s(f, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf_s(f, "%d",&a[i]);
	fclose(f);
}
void ghifile(int a[], int n)
{
	fopen_s(&g, "NUM.OUT", "wt");
	if (!g)
	{
		cout << "khong mo duoc file g";
		return;
	}
	fprintf(g, "Cau 1: %d\n", capsntcungnhau(a, n));
	demxuathien(a, n);
	fprintf(g, "Cau 4: %d\n", ntdx(a, n));
	fprintf(g, "Cau 5: %d\n", tongbiendoi(a, n));
	fprintf(g, "Cau 6: %d\n", mangconmax(a, n));
	fprintf(g, "Cau 7: %d\n", kcmax(a, n));
	fclose(g);
}
int checknt(int a) 
{
	if (a < 2) return 0;
	int k = sqrt(a);
	for (int i = 2; i <= k; i++)
		if (a % i == 0) return 0;
	return 1;
}
int checkntdx(int n) {
	int temp1, temp2;
	temp1 = temp2 = n;
	do {
		temp1--;
	} while (!checknt(temp1));
	do {
		temp2--;
	} while (!checknt(temp2));
	int tb = (temp1 + temp2);
	tb /= 2.0;
	if (checknt(tb)) return 1;
	return 0;
}
int ucln(int a, int b)
{
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int capsntcungnhau(int a[], int n) {
	int dem = 1,nb=0;
	int b[MAX];
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
				flag = 1;
		}
		if (flag == 0)
			b[nb++] = a[i];
	}
	b[nb++] = a[n - 1];
	for(int i=0;i<nb-1;i++)
		for (int j= i+1; j < nb; j++)
		{
			if (ucln(b[i], b[j]) == 1)
			{
				dem++;
			}
		}
	return dem;
}
void demxuathien(int a[], int n) {
	int b[MAX],vt=0;
	int dem=0;
	int max = INT32_MIN;
	//mang danh dau
	for (int i = 0; i < n; i++)
		b[i] = 1;
	for (int i = 0; i < n - 1; i++)
		for (int j = i+1; j < n; j++)
			if (a[i] == a[j])
			{
				if (b[i] != 0)
				{
					b[i]++;
					b[j] = 0;
				}
			}
	for (int i = 0; i < n; i++)
	{
		if (b[i] > max)
		{
			vt = i;
			max = b[i];
		}
		if (b[i] == 1)
			dem++;
	}
	fprintf(g, "Cau 2: %d %d\n", a[vt],max);
	fprintf(g, "Cau 3: %d\n", dem);
}
int ntdx(int a[], int n) 
{
	int dem = 0;
	for (int i = 1; i < n; i++)
	{
		if (checknt(a[i]) && checkntdx(a[i]))
			dem++;
	}
	return dem;
}
int tongbiendoi(int a[], int n) {
	int b[MAX];
	int s = 0;
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	for (int i = 0; i < n; i++)
	{
		while (!checknt(b[i])) {
			b[i]++;
		}
	}
	for (int i = 0; i < n; i++)
		s += b[i];
	return s;
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
int kcmax(int a[], int n) {
	int kc = 0, max = INT32_MIN;
	for (int i = 0; i < n - 1; i++)
	{
		if ((a[i] <= n && checknt(a[i])) &&
			(a[i+1] <= n && checknt(a[i+1])))
		{
			kc = abs((a[i] - a[i + 1]));
			if (kc > max)
				max = kc;
		}
	}
	if (kc == 0) return kc;
	return max;
}
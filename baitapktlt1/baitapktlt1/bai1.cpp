#include<iostream>
#include<fstream>
using namespace std;
void docfile(int a[],int &n)
{
	FILE* f;
	fopen_s(&f,"mang.inp", "rt");
	if (!f)
	{
		cout << "khong mo duoc file f";
		return;
	}
    int temp = sizeof(int);
    n = (sizeof(f) * temp);
	for (int i = 0; i < n; i++)
		fscanf_s(f, "%d", &a[i]);
	fclose(f);
}
int tongmang(int a[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[i];
	return s;
}
void hoanvi(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void sapxeptang(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				hoanvi(a[i], a[j]);
}
void ghifile(int a[], int n) {
	FILE* g;
	fopen_s(&g, "mang.out", "wt");
	if (!g)
	{
		cout << "khong mo duoc file g";
		return;
	}
	fprintf(g, "Tong mang la: %d\n", tongmang(a, n));
	fprintf(g, "mang sau khi sap xep tang la: ");
	for (int i = 0; i < n; i++)
		fprintf(g, "%d ", a[i]);
	fclose(g);
}
int main()
{
    int a[100];
	int n;
    docfile(a,n);
	sapxeptang(a, n);
	ghifile(a, n);
	return 0;
}
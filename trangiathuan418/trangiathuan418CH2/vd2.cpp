
							//chuong trinh chay hoan chinh tren moi truong dev-c++

#include<iostream>
#define maxn 1000001
using namespace std;
void hoanvi(int& a, int& b)
{
	int temp = a; a = b; b = temp;
}
void chuyenmang(int a[], int n, int k) {
	int dem = 1, temp = k-1,temp2=k;
	while (dem != (k+1))
	{
		hoanvi(a[dem], a[temp2 + 1]);
		hoanvi(a[temp2 + 1], a[n - temp]);
		dem++;
		temp--;
		temp2++;
	}
}
void docfile(int a[], int& n,int &k)
{
	FILE* f=fopen("VD2.INP", "rt");
	if (!f)
	{
		cout << "khong mo duoc file f";
		return;
	}
	fscanf(f, "%d%d", &n,&k);
	for (int i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}
void ghiketqua(int a[], int n, int k)
{
	FILE* f=fopen("VD2.OUT", "wt");
	for (int i = 1; i <= n; i++)
	{
		fprintf(f, "%d ", a[i]);
		if (i % 10 == 0) fprintf(f, "\n");
	}
	fclose(f);
}
int main()
{
	int n,k;
	int* a;
	a = new int[maxn];
	docfile(a, n,k);
	chuyenmang(a, n, k);
	ghiketqua(a, n, k);
	delete a;
	return 0;
}

#include<iostream>
#define max 20
using namespace std;
typedef struct MONDO {
	int w;
	int v;
	int num;
};
//tang dan theo trong luong
void sapxep1(MONDO a[], int n);
//giam dan theo gia tri
void sapxep2(MONDO a[], int n);
//giam dan theo don gia
void sapxep3(MONDO a[], int n);
int thamlam(MONDO a[], int n, int wmax, int soluong[]);
void docfile(const char filename[], MONDO a[], int& n)
{
	FILE* fp;
	fopen_s(&fp, filename, "rt");
	if (!fp)
	{
		cout << "khong mo duoc file";
		return;
	}
	fscanf_s(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf_s(fp, "%d", &a[i].w);
		fscanf_s(fp, "%d", &a[i].v);
		fscanf_s(fp, "%d", &a[i].num);
	}
	fclose(fp);
}
void indo(MONDO a)	
{
	cout << "(" << a.w << "," << a.v << "," << a.num << ")" << endl;
}
int main()
{
	MONDO a[max];
	int n,wmax,soluong[max];
	docfile("E:/caitui.TXT", a, n);
	for (int i = 0; i < n; i++)
		indo(a[i]);
	wmax = 100;
	cout << "tong gia tri lay duoc la: " << thamlam(a, n, wmax, soluong) << endl;
	return 0;
}
void hoanvi(MONDO &a, MONDO &b)
{
	MONDO t = a;
	a = b;
	b = t;
}
//tang dan theo trong luong
void sapxep1(MONDO a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].w > a[j].w)
				hoanvi(a[i], a[j]);
}
//giam dan theo gia tri
void sapxep2(MONDO a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].v < a[j].v)
				hoanvi(a[i], a[j]);
}
//giam dan theo don gia
void sapxep3(MONDO a[], int n)
{
	float tam, tam1;
	for(int i=0;i<n-1;i++)
		for (int j = i + 1; j < n; j++)
		{
			tam =(float)a[i].w / a[i].v;
			tam1 = (float)a[j].w / a[j].v;
			if (tam < tam1)
				hoanvi(a[i], a[j]);
		}
}
int thamlam(MONDO a[], int n, int wmax, int soluong[])
{
	int tonggt = 0;
	//sapxep1(a, n);
	//sapxep2(a, n);
	sapxep3(a, n);
	for (int i = 0; i < n; i++)
	{
		soluong[i] = wmax / a[i].w;
		wmax -= soluong[i];
		tonggt = soluong[i] * a[i].v;
	}
	return tonggt;
}
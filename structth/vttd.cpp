#include<iostream>
#include<math.h>
#define max 50
using namespace std;
struct diem
{
	int x, y;
	float kctam, kc;
};
void nhapdiem(diem d[], int n);
void xuatdiem(diem d[], int n);
int dem(diem d[], int n);
void tungmax(diem d[], int n);
void gantd(diem d[], int n);
void gannhau(diem d[], int n);
void xanhau(diem d[], int n);
int main()
{
	int n;
	diem d[max];
	cout << "nhap so diem can tinh: "; cin >> n;
	nhapdiem(d, n);
	xuatdiem(d, n);
	cout << "co " << dem(d, n) << " diem co hoanh do duong" << endl;
	tungmax(d, n);
	gantd(d, n);
	gannhau(d, n);
	xanhau(d, n);
	return 0;
}
void nhapdiem(diem d[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap toa do x cua diem thu " << i << " :"; cin >> d[i].x;
		cout << "nhap toa do y cua diem thu " << i << " :"; cin >> d[i].y;
		d[i].kctam = sqrt(pow(d[i].x, 2) + (pow(d[i].y, 2)));
	}
}
void xuatdiem(diem d[], int n)
{
	for (int i = 0; i < n; i++)
		cout << "toa do cua diem thu " << i << " la: (" << d[i].x << "," << d[i].y << ")" << endl;
}
int dem(diem d[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (d[i].x > 0)
			dem++;
	}
	return dem;
}
void tungmax(diem d[], int n)
{
	int vt = 0, max1 = -1000000;
	for (int i = 0; i < n; i++)
	{
		if (d[i].y > max1)
		{
			max1 = d[i].y;
			vt = i;
		}
	}
	cout << "diem co tung do lon nhat trong mang la: (" << d[vt].x << "," << d[vt].y << ")" << endl;
}
void gantd(diem d[], int n)
{
	int vitri = 0;
	float max1 = 1000000;
	for (int i = 0; i < n; i++)
	{
		if (d[i].kctam < max1)
		{
			max1 = d[i].kctam;
			vitri = i;
		}
	}
	cout << "diem gan voi goc toa do nhat la: (" << d[vitri].x << "," << d[vitri].y << ")" << endl;
}
void gannhau(diem d[], int n)
{
	float min = 1000000;
	int vt1 = 0, vt2 = 0, temp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			d[temp].kc = sqrt(pow((d[i].x - d[j].x), 2) + (pow((d[i].y - d[j].y), 2)));
			if (d[temp].kc < min)
			{
				min = d[temp].kc;
				vt1 = i;
				vt2 = j;
			}
			temp++;
		}
	}
	cout << "hai diem gan nhau nhat trong mang la: (" << d[vt1].x << "," << d[vt1].y << ")	(" << d[vt2].x << "," << d[vt2].y << ")" << endl;
}
void xanhau(diem d[], int n)
{
	float max1 = -1;
	int vt1 = 0, vt2 = 0, temp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (d[temp].kc > max1)
			{
				max1 = d[temp].kc;
				vt1 = i;
				vt2 = j;
			}
			temp++;
		}
	}
	cout << "hai diem xa nhau nhat trong mang la: (" << d[vt1].x << "," << d[vt1].y << ")	(" << d[vt2].x << "," << d[vt2].y << ")" << endl;
}
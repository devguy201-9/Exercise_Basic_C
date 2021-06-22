#include<iostream>
#include<math.h>
using namespace std;
void nhapson(int &n);
void tongmax(int n);
void songuyentovahc(int n);
void songuyento3(int n);
void demntdx(int n);
void capso(int n);
void bacapso(int n);
void tichnt(int n);
void uclnvabcnn(int n);
void xuatcp(int n);
void capsouoc(int n);
int main()
{
	int n;
	nhapson(n);
	tongmax(n);
	songuyentovahc(n);
	songuyento3(n);
	demntdx(n);
	capso(n);
	bacapso(n);
	cout << "cau 8: ";
	tichnt(n);
	uclnvabcnn(n);
	xuatcp(n);
	capsouoc(n);
	return 0;
}
void nhapson(int& n)
{
	cin >> n;
}
void tongmax(int n)
{
	int tam, dv, s;
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		tam = i;
		s = 0;
		while (tam > 0)
		{
			dv = tam % 10;
			s = s + dv;
			tam = tam / 10;
		}
		if (s >= max)
			max = s;
	}
	cout << "cau 1: " << max << endl;
}
int checknt(int n)
{
	if (n < 2) return 0;
	int k = sqrt(n);
	for (int i = 2; i <= k; i++)
		if (n % i == 0) return 0;
	return 1;
}
int checkhc(int n)
{
	int tam = 0;
	int temp = n;
	for (int i = 2; i <= temp / 2; i++)
	{
		if (i % temp == 0)
			tam = tam + i;
		if (tam == n) return 1;
		return 0;
	}
}
void songuyentovahc(int n)
{
	int dem = 0, demhc = 0;
	for (int i = 1; i <= n; i++)
		if (checknt(i)) dem++;
	for (int i = 1; i <= n; i++)
		if (checkhc(i)) demhc++;
	cout << "cau 2: " << dem << " " << demhc;
	cout << endl;
}
int chonnt(int n)
{
	switch (n)
	{
	case 2:
	case 3:
	case 5:
	case 7:return 1;
	case 1:
	case 4:
	case 6:
	case 8:
	case 9: return 0;
	}
}
bool nguyentotach(int n)
{
	int dv, temp=0;
	while (n != 0)
	{
		dv = n % 10;
		if (chonnt(dv) == 1)
		{
			n = n / 10;
			temp = 1;
		}
		else
		{
			temp = 0;
			break;
		}
	}
	if (temp == 1) return 1;
	return 0;
}
void songuyento3(int n)
{

	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (nguyentotach(i) == 1 && checknt(i) == 1)
			dem++;
	}
	cout << "cau 3: " << dem << endl;
}
int doixung(int n)
{
	int t = n;
	int dv, dn = 0;
	while (t != 0)
	{
		dv = t % 10;
		dn = dn * 10 + dv;
		t = t / 10;
	}
	if (dn == n) return 1;
	return 0;
}
void demntdx(int n)
{
	int dem = 0;
	for (int i = 10; i <= n; i++)
		if (checknt(i) && doixung(i)) dem++;
	cout << "cau 4: " << dem << endl;
}
void capso(int n)
{
	int dem = 0;
	int s = 0;
	for (int i = 1; i < n / 2.0; i++)
	{
		s = n - i;
		dem++;
	}
	cout << "cau 6: " << dem << endl;
}
void bacapso(int n)
{
	int dem = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			for (int k = 1; k < n; k++)
			{
				if (i + j + k == n && i != j && j != k && i != k)
					dem++;
			}
		}
	}
	cout << "cau 7: " << dem / 6;
	cout << endl;
}
void tichnt(int n)
{
	for (int i = 2; i <= n; i++)
		while ((n % i == 0) && checknt(i))
		{
			cout << i << " ";
			n = n / i;
		}
	cout << endl;
}
int ucln(int a, int b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	if (a < b)
	{
		int temp = a;
		a = b; b = temp;
	}
	int r = a % b;
	while (r > 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int bcnn(int a, int b)
{
	if (a == 0) return 0;
	if (b == 0) return 0;
	return (a * b) / ucln(a, b);
}
int tachso1(int n)
{
	int temp = n;
	int kq = ucln(0, temp % 10);
	temp = temp / 10;
	while (temp > 0)
	{
		kq = ucln(kq, temp % 10);
		temp = temp / 10;
	}
	return kq;
}
int tachso2(int n)
{
	int temp = n;
	int kq = bcnn(1, temp % 10);
	temp = temp / 10;
	while (temp > 0)
	{
		kq = bcnn(kq, temp % 10);
		temp = temp / 10;
	}
	return kq;
}
void uclnvabcnn(int n)
{
	cout << "cau 9: " << tachso1(n) << " " << tachso2(n);
	cout << endl;
}
int chuson(int n)
{
	int d = 1;
	while (n >= 10)
	{
		d++;
		n = n / 10;
	}
	return d;
}
int socptieptheo(int n)
{
	n++;
	while (sqrt(n) != int(sqrt(n)))
		n++;
	return n;
}
long hammu(int x, int n)
{
	long p = 1;
	for (int i = 1; i <= n; i++)
		p = p * x;
	return p;
}
int vitricp(int n)
{
	int a = 1, dem = 0, b, temp;
	while (dem < n)
	{
		int d = chuson(a);
		temp = a;
		while (d > 0)
		{
			b = temp / hammu(10, d - 1);
			temp = temp % hammu(10, d - 1);
			dem++;
			d = d - 1;
			if (dem == n) return b;
		}
		a = socptieptheo(a);
	}
}
void xuatcp(int n)
{
	cout << "cau 10: " << vitricp(n);
	cout << endl;
}
int tonguoc(int n)
{
	int s = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
			s = s + i;
	}
	return s;
}
void capsouoc(int n)
{
	int tam, dem = 0;
	for (int i = 2; i <= n; i++)
	{
		tam = tonguoc(i);
		if (tam <= n && tonguoc(tam) == i && tam > i)
			dem++;
	}
	cout << "cau 11: " << dem;
}

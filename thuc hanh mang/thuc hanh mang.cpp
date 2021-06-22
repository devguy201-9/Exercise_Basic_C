#include<iostream>
#include<math.h>
#define max 100
using namespace std;
void nhapmang(int a[], int n);
void xuatmang(int a[], int n);
void sapxeptang(int a[], int n);
void sapxepgiam(int a[], int n);
void demmang(int a[],int b[], int n);
void xuatmang1(int a[], int b[], int n);
void saochep(int a[], int b[], int n,int &nb);
void xuatnb(int a[], int b[], int n, int nb);
void tachmang(int a[], int c[], int d[], int n);
void fibo(int n);
void xuatcp(int a[], int n);
void checktrung(int a[], int n);
void xuatnt(int a[], int n);
void demamduong(int a[], int n);
void demnt(int a[], int n);
float tbmangduong(int a[], int n);
float tongvatb(int a[], int n,int &s);
void tonggtmang(int a[], int n);
void demlanxuathien(int a[], int b[], int n);
int main()
{
	int b[max] = { 0 };
	int n,nb=0,s;
	int a[max],c[max],d[max];
	cout << "nhap mang: ";
	cin >> n;
	nhapmang(a, n);
	cout << "mang la: ";
	/*xuatmang(a, n);
	cout << endl;
	sapxepgiam(a, n);
	xuatmang(a, n);
	cout << endl;
	sapxeptang(a, n);
	xuatmang(a, n);
	cout << endl;
	demmang(a, b, n);
	xuatmang1(a, b, n);
	cout << endl;
	cout << "so le cua mang: ";
	saochep(a, b,n,nb);
	xuatnb(a, b, n, nb);
	cout << endl;
	checktrung(a, n);
	fibo(n);//nhap n la gioi han fibo
	cout << endl;
	xuatnt(a, n);
	demamduong(a, n);
	demnt(a, n);
	cout <<"\ntb so >0 trong mang: ";
	cout<<tbmangduong(a, n);*/
	cout<<tongvatb(a, n,s);
	//tonggtmang(a, n);
	//demlanxuathien(a, b, n);
	//xuatcp(a, n);
	return 0;

}
void nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void xuatmang(int a[], int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
}
void sapxepgiam(int a[], int n)
{
	int LON = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				LON = a[i];
				a[i] = a[j];
				a[j] = LON;
			}
		}
	}
}
void sapxeptang(int a[], int n)
{
	int nho = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				nho = a[j];
				a[j] = a[i];
				a[i] = nho;
			}
		}
	}
}
void xuatmang1(int a[], int b[], int n)
{		
	int max1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[i] > max1) max1 = b[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i] == max1)
		{
			cout << "phan tu " << a[i] << " xuat hien nhieu nhat la: " << b[i] << " lan";
			cout << endl;
		}
	}
}
void demmang(int a[],int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[i] == a[j])
				b[i]++;
		}
	}
}
void saochep(int a[], int b[], int n,int &nb)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			b[nb++] = a[i];
		}
	}
}
void xuatnb(int a[], int b[], int n, int nb)
{
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
}
void tachmang(int a[], int c[], int d[], int n)
{
	cout << "mang >=0: ";
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			c[i] = a[i];
			cout << c[i] << " ";
		}
	}
	cout << endl;
	cout << "mang <0: ";
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			d[i] = a[i];
			cout << d[i] << " ";
		}
	}
}
void fibo(int n)
{
	int next = 0, first = 1, s = 0;
	while (next < n / 2)
	{
		cout << first << " ";
		s = next + first;
		next = first;
		first = s;
	}
}
void checktrung(int a[], int n)
{
	cout << "nhap mang :";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				i--;
				cout << "nhap lai" << endl;
				break;
			}
		}
	}
}
int checknt(int x)
{	
	if (x < 2) return 0;
	int k = sqrt(x);
	for (int i = 2; i <= k; i++)
		if (x % i == 0) return 0;
	return 1;
}
void xuatnt(int a[], int n)
{	
	cout << "so nt: ";
	for (int i = 0; i < n; i++)
	{
		if (checknt(a[i]) == 1)
		{
			cout << a[i] << " ";
		}
	}
	cout << endl;
}
void demamduong(int a[], int n)
{
	int dem1 = 0, dem2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
			dem1++;
		else
			dem2++;
	}
	cout << "co " << dem1 << " so duong" << endl;
	cout << "co " << dem2 << " so am" << endl;;
}
void demnt(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (checknt(a[i])) dem++;
	cout << "co " << dem << " so nguyen to";
}
float tbmangduong(int a[], int n)
{
	int dem = 0, s = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			dem++;
			s = s + a[i];
		}
	}
	return (float)s / dem;
}
float tongvatb(int a[], int n,int &s)
{
	int dem = 0;
	s = 0;
	for (int i = 0; i < n; i++)
	{
		dem++;
		if (a[i] >= 0)
		{
			s = s + a[i];
		}
		return (float)s / dem;
	}
}
void tonggtmang(int a[], int n)
{
	int s = 0, dv = 0;
	for (int i = 0; i < n; i++)
	{
		while (a[i] > 0)
		{
			dv = a[i] % 10;
			s = s + dv;
			a[i] = a[i] / 10;
		}
	}
	cout << "tong cac chu so cua mang: " << s << endl;
}
void demlanxuathien(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[i] == a[j])
				b[i]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " xuat hien " << b[i] << " lan";
		cout << endl;
	}
}
int checkcp(int a)
{
	if (a == int(sqrt(double(a))) * int(sqrt(double(a)))) return 1;
	return 0;
}
void xuatcp(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (checkcp(a[i]) == 1 && i%2!=0)
			cout <<a[i]<<" ";
	}
}

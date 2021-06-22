#include<iostream>
#include<math.h>
#define max 100
using namespace std;
void nhapmang(int a[], int& n);
void xuatmang(int a[], int n);
int amduongxenke(int a[], int n);
int tangdan(int a[], int n);
int mangsong(int a[], int n);
int mangdoixung(int a[], int n);
void capsocong(int a[], int n);
int demsochan(int a[], int n);
int demsole(int a[], int n);
void tachmang(int a[], int b[], int c[], int n);
void tachchanle(int b[], int c[], int d[], int n, int dem, int dem1);
void dodaidayconmax(int a[], int n);
void tongdayconmax(int a[], int n);
void themxcuoimang(int a[], int &n, int x);
void themxdaumang(int a[], int& n, int x);
void themktrongmang(int a[], int &n, int x, int k);
void xoacuoimang(int a[], int& n);
void xoadaumang(int a[], int& n);
void xoakcuamang(int a[], int& n, int k);
int main()
{
	int n,x,k;
	int a[max],b[max],c[max],d[max];
	nhapmang(a, n);
	/*if (amduongxenke(a, n) == 0)
		cout << "k phai la mang am duong xen ke" << endl;
	else
		cout << "la mang am duong xen ke" << endl;*/
	/*if (mangsong(a, n) == 1)
		cout << "mang co tc dang song" << endl;
	else
		cout << "mang k co tc dang song" << endl;*/
	/*if(tangdan(a,n)==0)
		cout<<"mang k tang dan"<<endl;
	else
		cout<<"man tang dan"<<endl;*/
	/*if (mangdoixung(a, n) == -1)
		cout << "k la mang doi xung" << endl;
	else
		cout << "la mang doi xung" << endl;*/
	//capsocong(a, n);
	/*int x = demsochan(a, n);
	int y = demsole(a, n);
	tachmang(a, b, c, n);
	tachchanle(b,c,d,n,x,y);*/
	//dodaidayconmax(a, n);
	//tongdayconmax(a, n);
	//cout << "nhap so can them vao mang: "; cin >> x;
	//themxcuoimang(a, n, x);
	//themxdaumang(a, n, x);
	/*cout << "nhap vi tri k them: "; cin >> k;
	themktrongmang(a, n, x, k);*/
	//xoacuoimang(a, n);
	//xoadaumang(a, n);
	cout << "nhap vi tri xoa k: "; cin >> k;
	xoakcuamang(a, n, k);
	xuatmang(a, n);
	return 0;
}
void nhapmang(int a[], int& n)
{
	cin >> n;
	cout << "nhap mang: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int amduongxenke(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] * a[i + 1] > 0) return 0;
	return 1;
}
int tangdan(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[i + 1])
			return 0;
	}
	return 1;
}
int mangsong(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((a[i] > a[i + 1] && a[i + 1] < a[i + 2]) || (a[i] < a[i + 1] && a[i + 1] > a[i + 2]))
			return 1;
	}
	return -1;
}
int mangdoixung(int a[], int n)
{
	for (int i = 0; i < n/2; i++)
	{
		if (a[i] != a[n - i - 1])
			return -1;
	}
	return 1;
}
void capsocong(int a[], int n)
{
	int d = a[1] - a[0];
	int dem =0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[0] + i * d)
			dem++;
	}
	if(dem==0)
		cout << "mang la cap so cong,cong sai la: "<<d << endl;
	else
		cout << "mang khong phai la mot cap so cong" << endl;
}
void tachmang(int a[], int b[], int c[], int n)
{
	int k = 0, j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[j++] = a[i];
		}
		else
		{
			c[k++] = a[i];
		}
	}
}
int demsochan(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			dem++;
		}
	}
	return dem;
}
int demsole(int a[], int n)
{
	int dem1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			dem1++;
		}
	}
	return dem1;
}
void tachchanle(int b[],int c[],int d[], int n,int dem,int dem1)
{
	int tam=0;
	for (int j = 0; j < dem; j++)
	{
		d[tam++] = b[j];
	}
	for (int k = 0; k < dem1; k++)
	{
		d[tam++] = c[k];
	}
	cout << "sap xep chan le: ";
	for (int i = 0; i < n; i++)
	{
		cout << d[i] << " ";
	}
}
		//gop chan le k can sap xep lai
/*int nc = 0;
int i = j = 0;
while ((i!=na-1)||(j!=nb-1))
{
	if (a[i] <b[j])
		c[nc++] = a[i++];
	else
		c[nc++] = b[j++];
}
while (i < na - 1)
{
	c[nc++] = a[i++];
}
while (j < nb - 1)
{
	c[nc++] = a[j++];
}*/

/*int i = 0, j = n - 1;
while (i < j)
{
	while (a[i] % 2 == 0)
		i++;
	while (a[j] % 2 != 0)
		j--;
	if (i < j)
		hoanvi(a[i], a[j]);
}*/
void dodaidayconmax(int a[], int n)
{
	int dem = 0, lon = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i + 1])
		{
			dem++;
			if (dem > lon)
				lon = dem;
		}
		else
			dem = 0;
	}
	cout << "do dai day con tang dai nhat: " << lon;
	cout << endl;
}
void tongdayconmax(int a[], int n)
{
	int s = 0,lon1=0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			s += a[i];
			if (s > lon1)
				lon1 = s;
		}
		else
			s = 0;
	}
	cout << "tong lon nhat cua cac day con la: " << lon1;
	cout << endl;
}
void themxcuoimang(int a[], int &n, int x)
{
	a[n] = x;
	n++;
}
void themxdaumang(int a[], int& n, int x)
{
	for (int i=n;i>0;i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	n++;
}
void themktrongmang(int a[], int& n, int x, int k)
{
	for (int i = n; i > k; i--)
	{
		a[i] = a[i - 1];
		a[k] = x;
		n++;
	}
}
void xoacuoimang(int a[], int& n)
{
	a[n - 1] = a[n];
	n--;
}
void xoadaumang(int a[], int& n)
{
	for (int i =0;i<n;i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void xoakcuamang(int a[], int& n, int k)
{
	for (int i = k; i < n - 1; i++)
	{
		a[i] = a[i + 1];
		n--;
	}
}

//sap so 0 ve dau 1 ve cuoi

b[2]
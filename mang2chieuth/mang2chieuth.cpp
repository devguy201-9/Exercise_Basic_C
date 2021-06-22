#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#define max 100
#define col 20
#define row 20
using namespace std;
void nhapmang(int a[][col], int n, int m);
void xuatmang(int a[][col], int n, int m);
void taomangrand(int a[][col], int n, int m);
void taomang1chieu(int a[][col], int z[], int n, int m);
void mangcungkt(int a[][col],int b[][col],int z[], int n, int m, int &q, int &w,int &tam);
void chuyenvi(int a[][col],int b[][col], int n,int m);
void hoanvi2dong(int a[][col], int n, int m, int d1, int d2);
void chanletanggiamtheodong(int a[][col], int n, int m);
void tongtheodong(int a[][col], int n, int m, int k);
void tongxungquanh(int a[][col], int n, int m);
void dongtongmax(int a[][col], int n, int m,int &tam);
void demntdongk(int a[][col], int n, int m, int k1);
void chanmaxdong(int a[][col], int n, int m, int& tam);
void vitriminmax(int a[][col], int n, int m);
int main()
{
	int n, m,q,w,tam;
	int d1, d2,k,k1;
	int a[row][col],z[max],b[row][col];
	cout << "nhap so hang :"; cin >> n;
	cout << "nhap so cot :"; cin >> m;
	//nhapmang(a, n, m);
	//xuatmang(a, n, m);
	taomangrand(a, n, m);
	//xuatmang(a, n, m);
	//taomang1chieu(a, z, n, m);
	//mangcungkt(a,b,z, n, m, q, w,tam);
	//xuatmang(b, q, w);
	xuatmang(a, n, m);
	//chuyenvi(a,b, n,m);
	//xuatmang(b, m,n);
	/*cout << "nhap 2 dong can hoan vi :" << endl;
	cin >> d1 >> d2;
	hoanvi2dong(a, n, m, d1, d2);
	xuatmang(a, n, m);*/
	//chanletanggiamtheodong(a, n, m);
	//xuatmang(a, n, m);
	//cout << "nhap dong can tinh tong :"; cin >> k;
	//tongtheodong(a, n, m,k);
	//tongxungquanh(a, n, m);
	//dongtongmax(a, n, m,tam);
	cout << "dem nt dong thu k: "; cin >> k1;
	demntdongk(a, n, m,k1);
	//chanmaxdong(a,n, m,tam);
	return 0;
}
void nhapmang(int a[][col], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
}
void xuatmang(int a[][col], int n, int m)
{
	cout << "xuat mang: " << endl;
	for (int i= 0;i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout <<"	" <<a[i][j];
		}
		cout << endl;
	}
}
void taomangrand(int a[][col], int n, int m)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while(a[i][j]==a[i][j+1])
				a[i][j] = rand() % 100 + 1;
		}
	}
}
void taomang1chieu(int a[][col], int z[], int n, int m)
{
	int tam = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			z[tam++] = a[i][j];
		}
	}
	cout << "mang 1 chieu :" << endl;
	for (int k = 0; k < n * m; k++)
	{
		cout << z[k] << " ";
	}
}
void mangcungkt(int a[][col],int b[][col],int z[], int n, int m, int &q, int &w,int &tam)
{
	cout << "nhap kich thuoc ma tran tuong tu " << n << "*" << m;
	cout << endl;
	cin >> q >> w;
	tam = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			z[tam++] = a[i][j];
		}
	}
	for (int l = 0; l < q; l++)
	{
		for (int t = 0; t < w;)
		{
			for (int k = 0; k < q * w; k++)
			{
				b[l][t] = z[k];
				t++;
			}
		}
	}
}
void hoanvi(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}
void chuyenvi(int a[][col],int b[][col], int n,int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[j][i] = a[i][j];
}
void hoanvi2dong(int a[][col], int n, int m, int d1, int d2)
{
	for (int i = 0; i <= n; i++)
		hoanvi(a[d1][i], a[d2][i]);
}
void chanletanggiamtheodong(int a[][col], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			if (a[i][j] % 2 != 0 && a[i][j + 1] % 2 == 0)
				hoanvi(a[i][j], a[i][j + 1]);
		}
	}
	for (int l = 0; l < n; l++)
	{
		for (int k = 0; k < m-1; k++)
		{
			if (a[l][k] > a[l][k + 1] && a[l][k] % 2 == 0)
				hoanvi(a[l][k], a[l][k + 1]);
			if (a[l][k] < a[l][k + 1] && a[l][k] % 2 != 0)
				hoanvi(a[l][k], a[l][k + 1]);
		}
	}
}
void tongtheodong(int a[][col], int n, int m, int k)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			s += a[i][j];
		}
		if (i != k)
			s = 0;
		else
			cout << "tong cua dong " << i << " la: " << s;
		cout << endl;
	}
}
void tongxungquanh(int a[][col], int n, int m)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += a[i][0] + a[i][m - 1];
	}
	for (int j = 1; j < m-1; j++)
	{
		s += a[0][j] + a[n - 1][j];
	}
	cout << "tong duong bien cua ma tran la: " << s;
	cout << endl;
}
void dongtongmax(int a[][col], int n, int m,int &tam)
{
	int max1 = -1,s=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			s += a[i][j];
		}
		if (s > max1)
		{
			max1 = s;
			tam = i;
		}
		s = 0;
	}
	cout << "hang thu " << tam << " co tong lon nhat :" << max1;
	cout << endl;
}
int checknt(int x)
{
	if (x < 2) return 0;
	int k = sqrt(x);
	for (int i = 2; i <= k; i++)
		if (x % i == 0) return 0;
	return 1;
}
void demntdongk(int a[][col], int n, int m, int k1)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (checknt(a[i][j]) == 1)
				dem++;
		}
		if (k1 != i)
			dem = 0;
		else
			cout << "co " << dem << " so nt o dong thu " << k1;
		cout << endl;
	}
}
void chanmaxdong(int a[][col] ,int n, int m, int& tam)
{
	int max1 = -1, dem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] %2 == 0)
				dem++;
		}
		if (dem > max1)
		{
			max1 = dem;
			tam = i;
		}	
		dem = 0;
	}
	cout << "mang chan max: " << endl;
	for (int k = 0; k < m; k++)
	{
		cout <<"	"<< a[tam][k];
	}
}
void vitriminmax(int a[][col], int n, int m)
{
	int max1 = -1,min=1000000;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; i < m-1; j++)
		{
			if (a[i][j] > a[i][j + 1] && a[i][j] < a[i + 1][j])
				max1 = min = a[i][j];
			if (a[i][j] < a[i][j + 1] && a[i][j] > a[i + 1][j])
			{
				max1 = a[i][j + 1];
				min = a[i + 1][j];
			}
		}
	}
}
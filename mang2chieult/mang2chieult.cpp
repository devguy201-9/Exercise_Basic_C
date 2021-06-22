#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
#define col 20
#define row 20
using namespace std;
//BAI 1
void nhapmanga(int a[][col], int n,int m);		//1 2 3 4 3 2 5 3 7      2 1 3 3 2 1 4 5 2 	
void nhapmangb(int b[][col], int n1, int m1);
void xuatmang(int a[][col], int n,int m);
void tongmang(int a[][col],int b[][col],int c[][col], int n, int m);
void tichmang(int a[][col], int b[][col], int c[][col], int n, int m);
void tichmangcodk(int a[][col],int b[][col],int c[][col], int n, int m);
//BAI 2
void sapxeptangtheocot(int a[][col], int n, int m);		//3 5 2 3 11 22 44 2 19 20 100 54
void tongchuso(int a[][col], int b[][col], int n, int m);
void thayntgan(int a[][col], int c[][col], int n, int m);
void nhapmang1(int a[][col], int n, int m);
void demxungquanh(int a[][col], int c[][col], int n, int m);
//BAI 3
int ntmin(int a[][col], int n, int m);
void gtmaxdong(int a[][col], int n, int m);
int tongchuso(int a[][col], int n, int m);
void checkntdk(int a[][col], int n, int m);
void hoanvi2dong(int a[][col], int n, int m, int d1, int d2);
void hoanvi2cot(int a[][col], int n, int m, int c1, int c2);
//void vitrimaxmincuaij(int a[][col], int n, int m);
void themhang(int a[][col], int &n, int m,int k);
void themcot(int a[][col], int n, int &m, int k1);
void xoadong(int a[][col], int &n, int m, int x);
//BAI 4
void checkdxdcc(int a[][col], int n);
void dcctang(int a[][col], int n);
void maxtamgiactren(int a[][col], int n);
void stamgiacduoi(int a[][col], int n);
int main()
{
	int n, m,n1,m1,k,k1,x;	
	int d1, d2, c1, c2;
	int a[row][col], b[row][col], c[row][col];
	cout << "nhap n dong mang 1: "; cin >> n;
	cout << "nhap m cot mang 1: "; cin >> m;
	nhapmanga(a, n, m);
	/*cout << "nhap n dong mang 2: "; cin >> n1;
	cout << "nhap m cot mang 2: "; cin >> m1;
	nhapmangb(b, n1, m1);
	cout << "mang 1: " << endl;
	xuatmang(a, n, m);
	cout <<"mang 2: "<< endl;
	xuatmang(b, n1, m1);
	tongmang(a, b, c, n,m);
	cout << "tong mang:" << endl;
	xuatmang(c, n, m);
	tichmang(a, b, c, n, m);
	cout << "tich mang:" << endl;
	xuatmang(c, n, m);
	tichmangcodk(a, b, c, n, m);
	cout << "tich mang a voi gt max tung hang cua mang b: " << endl;
	xuatmang(c, n, m);*/

	//BAI 2

	//sapxeptangtheocot(a, n, m);
	//xuatmang(a, n, m);
	//tongchuso(a, b, n, m);
	//xuatmang(b, n, m);
	//thayntgan(a,c, n, m);
	//xuatmang(c, n, m);
	//nhapmang1(a, n, m);
	//demxungquanh(a, c, n, m);

	//BAI 3

	/*cout << "nguyen to nho nhat cua mang la: " << ntmin(a, n, m);
	//cout << endl;
	gtmaxdong(a, n, m);
	cout << tongchuso(a, n, m) << endl;
	checkntdk(a, n, m);
	cout << "nhap 2 dong can hoan vi" << endl;
	cin >> d1>>d2;
	hoanvi2dong(a, n, m, d1, d2);
	cout << "nhap 2 cot can hoan vi" << endl;
	cin >> c1 >> c2;
	hoanvi2cot(a, n, m, c1,c2);*/
	//vitrimaxmincuaij(a, n, m);
	/*cout << "nhap dong thu k can them: "; cin >> k;
	themhang(a, n, m, k);
	xuatmang(a, n, m);
	cout << "nhap cot thu k can them: "; cin >> k1;
	themcot(a, n, m, k1);
	xuatmang(a, n, m);
	cout << "nhap vi tri dong can xoa "; cin >> x;
	xoadong(a, n, m, x);
	xuatmang(a, n, m);*/

	//BAI 4
	//checkdxdcc(a, n);			// 3x3  1 2 3 2 1 2 3 2 1
	//dcctang(a, n);
	maxtamgiactren(a, n);		// 4x4  7 8 9 1 6 5 1 3 1 4 7 14 4 5 9 8
	stamgiacduoi(a, n);
	return 0;
}
void nhapmanga(int a[][col], int n, int m)
{
	cout << "nhap mang:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
}
void nhapmangb(int b[][col], int n1, int m1)
{
	cout << "nhap mang:" << endl;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			cin >> b[i][j];
		}
	}
}
void xuatmang(int a[][col], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "	"<< a[i][j] ;
		}
		cout << endl;
	}
}
void tongmang(int a[][col],int b[][col],int c[][col], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
void tichmang(int a[][col], int b[][col], int c[][col], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
void tichmangcodk(int a[][col],int b[][col],int c[][col], int n, int m)
{
	int max1 = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] > max1)
				max1 = b[i][j];
		}
		for (int k = 0; k < m; k++)
		{
			c[i][k] = a[i][k] * max1;
		}
	}
}
//BAI 2
void sapxeptangtheocot(int a[][col], int n, int m)
{
	int tam;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > a[i+1][j])
			{
				tam = a[i][j];
				a[i][j] = a[i+1][j];
				a[i+1][j] = tam;
			}
		}
	}
}
void tongchuso(int a[][col], int b[][col], int n, int m)
{
	int dv = 0, s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(a[i][j]<10)
				b[i][j] = a[i][j];
			while (a[i][j]>=10)
			{
				dv = a[i][j] % 10;
				a[i][j] /= 10;
				s = dv+a[i][j];
				b[i][j] = s;
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
void thayntgan(int a[][col], int c[][col], int n, int m)
{
	int tam, tam1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (checknt(a[i][j]) == 0)
			{
				tam = a[i][j];
				tam1 = a[i][j];
				while (checknt(tam) == 0)
				{
					tam = tam - 1;
				}
				while (checknt(tam1) == 0)
				{
					tam1 = tam1 + 1;
				}
				if ((a[i][j] - tam) < (tam1 - a[i][j]))
					c[i][j] = tam;
				else
					c[i][j] = tam1;
			}
			else
				c[i][j] = a[i][j];
		}
	}
}
void nhapmang1(int a[][col], int n, int m)
{
	cout << "nhap mang:" << endl;
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < m+1; j++)
		{
			cin >> a[i][j];
		}
	}
}
void ganxungquanh(int a[][col], int n, int m)
{
	for (int i = 0; i < n + 2; i++)
		a[0][i] = 1;
	for (int j = 0; j < m + 2; j++)
		a[j][0] = 1;
	for (int l = 0; l < m + 2; l++)
		a[n+1][l] = 1;
	for (int k = 0; k < n+ 2; k++)
		a[k][m+1] = 1;
}
void demxungquanh(int a[][col], int c[][col], int n, int m)
{
	int dem;
	ganxungquanh(a, n, m);
	for (int i =1; i < n+1; i++)
	{
		for (int j = 1; j < m+1; j++)
		{
			dem = 0;
			if (a[i-1][j-1] % 2 == 0)
				dem++;
			if (a[i-1][j] % 2 == 0)
				dem++;
			if (a[i-1][j+1] % 2 == 0)
				dem++;
			if (a[i][j - 1] % 2 == 0)
				dem++;
			if (a[i][j+1] % 2 == 0)
				dem++;
			if (a[i+1][j -1] % 2 == 0)
				dem++;
			if (a[i+1][j] % 2 == 0)
				dem++;
			if (a[i+1][j + 1] % 2 == 0)
				dem++;
			c[i][j] = dem;
		}
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cout <<"	"<< c[i][j];
		}
		cout << endl;
	}
}
//BAI 3
int ntmin(int a[][col], int n, int m)
{
	int min = 10000000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (checknt(a[i][j]) == 1)
			{
				if (a[i][j] < min)
					min = a[i][j];
			}
		}
	}
	return min;
}
void gtmaxdong(int a[][col], int n, int m)
{
	int max1 = -1;
	cout << "gia tri max cua tung dong: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > max1)
				max1 = a[i][j];
		}
		cout << max1 << endl;
	}
}
int tongchuso(int a[][col], int n, int m)
{
	int dv = 0, s1 = 0;
	cout << "tong cac chu so cua mang: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (a[i][j] >= 10)
			{
				dv = a[i][j] % 10;
				s1 += dv;
				a[i][j] /= 10;
			}
			if (a[i][j] < 10)
				s1 = s1 + a[i][j];
		}
	}
	return s1;
}
void checkntdk(int a[][col], int n, int m)
{
	int tam, temp = 0;
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int tam1 = a[i][j];
			if (a[i][j] < 10 && checknt(a[i][j])==1)
				d++;
			if (a[i][j] >= 10)
			{
				while (tam1 > 0)
				{
					tam = tam1 % 10;
					temp = temp * 10 + tam;
					tam1 /= 10;
				}
			}
				if ((checknt(a[i][j]) == 1) && (checknt(temp) == 1))
					d++;
				temp = 0;
		}
	}
	cout << "co " << d << " so thoa dk so nt va dao nguoc cua no cung la so nguyen to" << endl;
}
void hoanvi(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}
void hoanvi2dong(int a[][col], int n, int m, int d1, int d2)
{
	for (int i = 0; i <= n; i++)
		hoanvi(a[d1][i], a[d2][i]);
	xuatmang(a, n, m);
}
void hoanvi2cot(int a[][col], int n, int m, int c1, int c2)
{
	for (int i = 0; i <= m; i++)
		hoanvi(a[i][c1], a[i][c2]);
	xuatmang(a, n, m);
}
/*void vitrimaxmincuaij(int a[][col], int n, int m)		//chua xong
{
	int imax = 0,jmax=0, jmin = 100000,imin=100000;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > a[imax][jmax])
			{
				imax = i;
				jmax = j;
			}
			if (a[i + 1][j] < a[imin][jmin])
			{
				imin = i;
				jmin = j;
			}	
			cout << imax << jmax << " " << imin << jmin << endl;
		}
	}
}
*/
void themhang(int a[][col], int &n, int m,int k)
{
	for (int i = n; i > k; i--)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = a[i - 1][j];
		}
		n++;
	}
	for (int j = 0; j < m; j++)
	{
		cout << "nhap phan tu cot " << j << " ";	
		cin >> a[k][j];
	}
}
void themcot(int a[][col], int n, int& m, int k1)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = m; j > k1; j--)
		{
			a[i][j] = a[i][j - 1];
		}
	}
	m++;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap phan tu hang " << i << " ";
		cin >> a[i][k1];
	}
}
void xoadong(int a[][col], int &n, int m, int x)
{
	for (int i = x; i < n - 1; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = a[i + 1][j];
	n--;
}
//BAI 4
int dxdcc(int a[][col], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i][j] != a[j][i])
				return 0;
	return 1;
}
void checkdxdcc(int a[][col], int n)
{
	if(dxdcc(a,n)==1)
		cout << "ma tran doi xung qua duong cheo chinh" << endl;
	else
		cout << "ma tran khong doi xung qua duong cheo chinh" << endl;
}
int checkdcctang(int a[][col], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i][i] > a[i + 1][i + 1])
			return 0;
	return 1;
}
void dcctang(int a[][col], int n)
{
	if (checkdcctang(a, n) == 1)
		cout << "duong cheo chinh cua ma tran tang" << endl;
	else
		cout << "duong cheo chinh cua ma tran khong tang" << endl;
}
void maxtamgiactren(int a[][col], int n)
{
	int max = a[0][0];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < i; j++)
		{
			if (a[j][i] > max)
				max = a[j][i];
		}
	cout << "gia tri max cua tam giac tren duong cheo chinh la: " << max;
	cout << endl;
}
void stamgiacduoi(int a[][col], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			s += a[i][j];
	cout << "tong phan tu cua tam giac duoi la: " << s;
	cout << endl;
}

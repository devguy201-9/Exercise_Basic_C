#include<iostream>
#include<math.h>
#include<cstring>
#define maximum 100
#define row 20
#define col 20
using namespace std;
struct phanso
{
	int tu, mau;
};
struct thisinh
{
	char mssv[10];
	char hoten[20];
	float conban, cnghanh1, cnghanh2,tong;
};
void nhapmang(int a[][col], int m, int n);
void xuatmang(int a[][col], int m, int n);
void cau4a(int a[][col], int m, int n);
void cau4b(int a[][col], int n);
void cau4c(int a[][col], int b[][col], float c[][col], int m, int n);
void nhapps(phanso ps[], int& n);
void xuatps(phanso ps[], int n);
void cau5a(phanso ps[], int n);
void nhapmangps(phanso x[][col], int m, int n);
void xuatmangps(phanso x[][col], int m, int n);
void cau5b(phanso x[][col], int m, int n);
void nhapts(thisinh s[], int n);
void xuatts(thisinh s[], int n);
void cau5c(thisinh s[], int n);
int main()
{
	int a[row][col],b[row][col], m, n;
	float c[row][col];
	phanso ps[maximum],x[row][col];
	thisinh s[maximum];
	/*cout << "nhap so hang cua mang: "; cin >> m;
	cout << "nhap so cot cua mang: "; cin >> n;
	nhapmang(a, m, n);
	xuatmang(a, m, n);
	cau4a(a, m, n);
	cout << "nhap so dong va cot cua ma tran: "; cin >> n;
	nhapmang(a, n, n);
	xuatmang(a, n, n);
	cau4b(a, n);
	cau4c(a, b, c, m, n);*/
	//nhapps(ps, n);
	//xuatps(ps, n);
	//cau5a(ps, n);
	cout << "nhap so hang cua mang: "; cin >> m;
	cout << "nhap so cot cua mang: "; cin >> n;
	nhapmangps(x, m, n);
	xuatmangps(x, m, n);
	cau5b(x, m, n);
	//cout << "nhap so luong thi sinh: "; cin >> n;
	//nhapts(s, n);
	//xuatts(s, n);
	//cau5c(s, n);
	return 0;
}
void nhapmang(int a[][col], int m, int n)
{
	cout << "nhap mang: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
}
void xuatmang(int a[][col], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "	" << a[i][j];
		}
		cout << endl;
	}
}
void xuatmang1(float c[][col], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "	" << c[i][j];
		}
		cout << endl;
	}
}
int checknt(int n)
{
	if (n < 2) return 0;
	int k = sqrt(n);
	for (int i = 2; i <= k; i++)
		if (n % i == 0) return 0;
	return 1;
}
int sodao(int n)
{
	int dv, s = 0;
	while (n != 0)
	{
		dv = n % 10;
		s = (s * 10) + dv;
		n /= 10;
	}
	return s;
}
bool doixung(int n)
{
	if (n == sodao(n))
		return 1;
	return 0;
}
void hoanvi(int& x, int& y)
{
	int tam = x; x = y; y = tam;
}
void cau4a(int a[][col], int m, int n)
{
	int s = 0,s1=0,dem=0,dem1=0;
	int min = a[0][0],max=-1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s += a[i][j];
			if (a[i][j] < min)
				min = a[i][j];
			s1 += a[i][j];
		}
		cout << "tong  cua dong thu " << i << " la: " << s1 << endl;
		s1 = 0;
	}
	cout << "tong cac phan tu cua mang= " << s << endl;
	cout << "gia tri nho nhat cua mang: " << min << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
			if (checknt(a[i][j])==1)
				dem++;
			if ((checknt(a[i][j])==1) && (doixung(a[i][j])==1))
				dem1++;
		}
		cout << "gia tri max cua dong thu " << i << " la: " << max << endl;
		max = -1;
	}
	cout << "co " << dem << " snt trong mang" << endl;
	cout << "co " << dem1 << " snt doi xung trong mang" << endl;
}
void cau4b(int a[][col], int n)
{
	int s = 0,s1=0,s2=0,s3=0;
	for (int i = 0; i < n; i++)
	{
		s += a[i][i];
		s1 += a[i][n - 1 - i];
	}
	for(int i=0;i<n;i++)
		for (int j = 0; j < i; j++)
		{
			s2 += a[j][i];
			s3 += a[i][j];
		}
	cout << "tong cac phan tu nam tren dcc la: " << s << endl;
	cout << "tong cac phan tu nam tren dcp la: " << s1 << endl;
	cout << "tong cac phan tu nam trong tam giac tren la: " << s2 << endl;
	cout << "tong cac phan tu nam trong tam giac duoi la: " << s3 << endl;
}
void cau4c(int a[][col], int b[][col], float c[][col], int m, int n)
{
	int min = 1000000,max=-1,tam;
	float tb;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < min)
				min = a[i][j];
			if (a[i][j] > max)
				max = a[i][j];
		}
		for (int k = 0; k < n; k++)
		{
			b[i][k] = a[i][k] * min;
			tam = min + max;
			tb = 1.0*tam / 2;
			cout << tb << endl;
			c[i][k] = a[i][k] * tb;
		}
		max = -1;
		min = 1000000;
	}
	cout << "mang b thoa dk 1 la: " << endl;
	xuatmang(b, m, n);
	cout << "mang b thoa dk 2 la: " << endl;
	xuatmang1(c, m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n-1; j++)
			for (int k = j + 1; k < n; k++)
				if (a[i][j] > a[i][k])
					hoanvi(a[i][j] , a[i][k]);
	cout << "mang a sau khi sap xep tang dan tren tung dong: " << endl;
	xuatmang(a, m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			for (int k = i + 1; k < m; k++)
				if (a[i][j] > a[k][j])
					hoanvi(a[i][j], a[k][j]);
	cout << "mang a sau khi sap xep tang dan tren tung dong va tung cot: " << endl;
	xuatmang(a, m, n);
}
void nhapps(phanso ps[], int& n)
{
	cout << "nhap so phan so can tinh: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap phan so thu "<<i<<" :" << endl;
		cin >> ps[i].tu;
		cin >> ps[i].mau;
	}
}
void xuatps(phanso ps[], int n)
{
	for (int i = 0; i < n; i++)
		cout << ps[i].tu << "/" << ps[i].mau << "	";
	cout << endl;
}
int ucln(int a, int b)
{
	int r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
void rutgon(phanso &ps)
{
	int c = ucln(ps.tu, ps.mau);
	ps.tu = ps.tu / c;
	ps.mau = ps.mau / c;
}
void pscong(phanso ps1, phanso ps2, phanso& ps)
{
	ps.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
	ps.mau = ps1.mau * ps2.mau;
}
void tongps(phanso ps[], int n)
{
	phanso pstong, pstemp;
	pstong.tu = 0;
	pstong.mau = 1;
	for (int i = 0; i < n; i++)
	{
		pscong(pstong, ps[i], pstemp);
		pstong = pstemp;
	}
	rutgon(pstong);
	cout << "tong gia tri cac phan so= " << pstong.tu << "/" << pstong.mau;
	cout << endl;
}
void tongpsmang(phanso x[][col],int m, int n)
{
	phanso pstong, pstemp;
	pstong.tu = 0;
	pstong.mau = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pscong(pstong, x[i][j], pstemp);
			pstong = pstemp;
		}
	}
	rutgon(pstong);
	cout << "tong gia tri cac phan so trong mang la: " << pstong.tu << "/" << pstong.mau;
	cout << endl;
}
void cau5a(phanso ps[], int n)
{
	int dem = 0;
	float max = -1;
	phanso psmax = ps[0];
	for (int i = 1; i < n; i++)
	{
		if (ps[i].tu < ps[i].mau && ps[i].tu * ps[i].mau>0)
			dem++;
		if (ps[i].tu * psmax.mau > psmax.tu* ps[i].mau)
			psmax = ps[i];
	}
	if (dem == 0)
		cout << "khong co phan so nho hon 1 va lon hon 0" << endl;
	else
		cout << "co " << dem << " phan so nho hon 1 va lon hon 0" << endl;
	rutgon(psmax);
	cout << "phan so co gia tri lon nhat trong mang: " << psmax.tu<<"/"<<psmax.mau<<endl;
	tongps(ps, n);
}
void nhapmangps(phanso x[][col], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "nhap phan so thu " << i << " cua mang: " << endl;
			cin >> x[i][j].tu;
			cin >> x[i][j].mau;
		}
	}
}
void xuatmangps(phanso x[][col], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "	" << x[i][j].tu<<"/"<<x[i][j].mau;
		}
		cout << endl;
	}
}
void cau5b(phanso x[][col], int m, int n)
{
	float max = -1;
	phanso psmax = x[0][0];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				break;
			else if (x[i][j].tu * psmax.mau > psmax.tu* x[i][j].mau)
				psmax = x[i][j];
		}
	}
	rutgon(psmax);
	cout << "phan so co gia tri lon nhat la: " << psmax.tu << "/" << psmax.mau << endl;
	tongpsmang(x, m, n);
}
void nhapts(thisinh s[], int n)
{
	char temp, temp1;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap mssv cua thi sinh thu " << i + 1 << endl;
		cin >> s[i].mssv;
		cout << "nhap ho va ten cua thi sinh thu " << i + 1 << endl;
		cin.ignore(32767, '\n');
		gets_s(s[i].hoten);
		cout << "nhap diem mon co ban cua thi sinh thu " << i + 1 << endl;
		cin >> s[i].conban;
		cout << "nhap diem mon c.nghanh 1 cua thi sinh thu " << i + 1 << endl;
		cin >> s[i].cnghanh1;
		cout << "nhap diem mon c.nghanh 2 cua thi sinh thu " << i + 1 << endl;
		cin >> s[i].cnghanh2;
		s[i].tong= s[i].conban + s[i].cnghanh1 + s[i].cnghanh2;
	}
}
void xuatts(thisinh s[], int n)
{
	cout << "					DANH SACH THI SINH" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "		______________________________________________________________________" << endl;
		cout << "		mssv cua thi sinh thu " << i << " la: " << s[i].mssv << endl;
		cout << "		ho va ten cua thi sinh thu " << i << " la: " << s[i].hoten << endl;
		cout << "		diem mon co ban cua thi sinh thu " << i << " la: " << s[i].conban << endl;
		cout << "		diem mon c.nghanh 1 cua thi sinh thu " << i << " la: " << s[i].cnghanh1 << endl;
		cout << "		diem mon c.nghanh 2 cua thi sinh thu " << i << " la: " << s[i].cnghanh2 << endl;
		cout << "		diem tong 3 mon cua thi sinh thu " << i << " la: " << s[i].tong << endl;
		cout << "		______________________________________________________________________" << endl << endl;
		cout << "		***********************************************************************" << endl;
	}
	cout << endl;
}
void cau5c(thisinh s[], int n)
{
	int dem = 0,max=-1;
	for (int i = 0; i < n; i++)
	{
		if (s[i].tong > max)
			max = s[i].tong;
		if ((s[i].conban < 5) || (s[i].cnghanh1 < 5) || (s[i].cnghanh2 < 5))
		{
			if (dem == 0)
				cout << "		thi sinh co it nhat 1 mon thi co diem nho hon 5" << endl << endl;
			cout << "		thi sinh co mssv la: " << s[i].mssv << endl;
			cout << "		thi sinh co ho ten la: " << s[i].hoten << endl << endl;
			dem++;
		}
	}
	if (dem == 0)
		cout << "		k thi sinh nao co diem thi nho hon 5" << endl << endl;
	cout << "		thi sinh co tong diem 3 mon lon nhat" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		if (s[i].tong == max)
		{
			cout << "		thi sinh co mssv la: " << s[i].mssv << endl;
			cout << "		thi sinh co ho ten la: " << s[i].hoten << endl;
			cout << "		tong diem 3 mon la: " << max << endl << endl;
		}
	}
}
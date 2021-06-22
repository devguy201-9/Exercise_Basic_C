#include<iostream>
#define max 100
#include<math.h>
using namespace std;
void nhapmang(int a[], int& n);//vi tri duong xai float
void xuatmang(int a[], int n);
void vitriduongmin(int a[], int n);
//int vitriduongnho(int a[], int n; int& vitri);
int vitrichan(int a[], int n);
int vitricplast(int a[], int n);
float gtduongnhonhat(float a[], int n);
int travent(int a[], int n);
void tong(int a[], int n, int gtx);
void timvathay(int a[], int n, int big);
void qhgap3(int a[], int n);
void sapxeptang(int a[], int n);
void tichlon1(int a[],int n);
void uclnvabcnn(int a[], int n);
int main()
{
	int n,gtx,big,k;
	int a[max];
	//float a[max];
	nhapmang(a, n);
	/*vitriduongmin(a, n);
	int vtchan = vitrichan(a, n);
	cout << "vi tri chan dau tien: " << vtchan << endl;
	int vtcp = vitricplast(a, n);
	cout << "vi tri cp cuoi cung: " << vtcp << endl;
	float xuatgtduongnhonhat = gtduongnhonhat(a, n);
	cout << "gia tri duong nho nhat: " << xuatgtduongnhonhat << endl;
	int xuatntdau = travent(a, n);
	cout << "so nt dau tien: " << xuatntdau << endl;
	cout << "nhap x: "; cin >> gtx;
	tong(a, n, gtx);
	cout << "nhap gia tri can thay= "; cin >> big;
	timvathay(a, n, big);
	xuatmang(a, n);
	qhgap3(a, n);*/
	//uclnvabcnn(a, n);
	sapxeptang(a, n);
	tichlon1(a, n);
	//cout << vitriduongnho(a, n, k);
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
void vitriduongmin(int a[], int n)
{
	int min = 100000000;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == min)
			cout <<"vi tri duong nho nhat la: "<<i<<endl;
	}
}
/*
int vitriduongnho(int a[], int n; int& vitri)
{
	int min = -1;
	vitri = -1;
	for (int i = 0; < n; i++)
	{
		if (a[i] > 0)
		{
			min = a[i];
			vitri = i;
			break;
		}
	}
	if (vitri != -1)
	{
		for (int i = viri + 1; i < n; i++)
		{
			if (a[i] < min)
			{
				min = a[i];
				vitri = i;
			}
		}
	}
	return vitri;
}*/
int vitrichan(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			return i;
		}
	}
	return -1;
}
int checkcp(int a)
{
	if (a == int(sqrt(double(a))) * int(sqrt(double(a))))
		return 1;
	else
		return 0;
}
int vitricplast(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (checkcp(a[i]) == 1)
		{
			return i;
		}
	}
	return -1;
}
float timgtduongnhonhat(float a[], int n) 
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			return a[i];
	}
	return -1;
}
float gtduongnhonhat(float a[], int n)
{
	float duongnhonhat = timgtduongnhonhat(a, n);
	if (duongnhonhat == -1)
		return -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0 && a[i] < duongnhonhat)
			duongnhonhat = a[i];
	}
	return duongnhonhat;
}
int checknt(int x)
{
	if (x < 2) return 0;
	int k = sqrt(x);
	for (int i = 2; i <= k; i++)
		if (x % i == 0) return 0;
	return 1;
}
int travent(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (checknt(a[i]) == 1)
			return a[i];
	}
	return -1;
}
void tong(int a[], int n, int gtx)
{
	cout << "gt tong bang " << gtx << " la: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] == gtx)
			{
				cout << a[i] << " " << a[j];
				cout << "	";
			}
		}
	}
	cout << endl;
}
void timvathay(int a[], int n, int big)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > big)
			a[i] = big;
	}
}
void qhgap3(int a[], int n)
{
	cout << "cac cap co qh gap 3: ";
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == 3 * a[j] || a[i] * 3 == a[j])
			{
				cout << a[i] << " " << a[j];
				cout << "	";
			}
		}
	}
	cout<< endl;
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
void tichlon1(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[n - 1] * a[n - 2] * a[n - 3] > a[0] * a[1] * a[2])
		{
			cout << a[n - 1] << " " << a[n - 2] << " " << a[n - 3];
			break;
		}
		if (a[n - 1] * a[n - 2] * a[n - 3] < a[0] * a[1] * a[2])
		{
			cout << a[0] << " " << a[1] << " " << a[2];
			break;
		}
	}
}
int ucln(int a, int b)
{
	int temp;
	while (b!=0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int bcnn(int a, int b)
{
	return (a * b / ucln(a, b));
}
int uclnmang(int a[], int n)
{
	int tam = ucln(a[0], a[1]);
	for (int i = 2; i < n; i++)
	{
		tam = ucln(tam, a[i]);
	}
	return tam;
}
int bcnnmang(int a[], int n)
{
	int tam = bcnn(a[0], a[1]);
	for (int i = 2; i < n; i++)
	{
		tam = bcnn(tam, a[i]);
	}
	return tam;
}
void uclnvabcnn(int a[], int n)
{
	int uc = uclnmang(a, n);
	int bc = bcnnmang(a, n);
	cout << "uoc chung lon nhat cua mang la: " << uc;
	cout << endl;
	cout << "boi chung nho nhat cua mang la: " << bc;
	cout << endl;
}

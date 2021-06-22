#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void nhapmang(int*& p, int n);
void xuatmang(int* p, int n);
void swap(int*& p, int n);
void nhapmatran(int**& b, int n);
void xuatmatran(int** b, int n);
int max(int** b, int n);
int main()
{
	int n;
	//int* p;
	int** b;
	//cout << "nhap so phan tu cua mang: "; cin >> n;
	//nhapmang(p, n);
	//xuatmang(p, n);
	//swap(p, n);
	//xuatmang(p, n);
	//p=nullptr;
	cout << "nhap ma tran vuong cap n: "; cin >> n;
	nhapmatran(b, n);
	xuatmatran(b, n);
	cout << "so lon nhat cua ma tran la " << max(b, n) << endl;
	for (int i = 0; i < n; i++)
		*(b + i) = nullptr;
	b = nullptr;
	return 0;
}
void nhapmang(int*& p,int n)
{
	srand(time(NULL));
	p = new int [n];
	for (int i = 0; i < n; i++)
		*(p + i) = rand() % 101;
}
void xuatmang(int*p, int n)
{
	cout << "mang la: " << endl;
	for (int i = 0; i < n; i++)
		cout << *(p+i) << " ";
	cout << endl;
}
void swap(int*& p, int n)
{
	int temp;
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (*(p + i) < *(p + j))
			{
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
}
void nhapmatran(int**& b, int n)
{
	srand(time(NULL));
	b = new int*[n];
	for (int i = 0; i < n; i++)
		*(b + i) = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(b + i) + j) = rand() % 151 - 50;
		}
	}
}
void xuatmatran(int** b, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(b + i) + j) << "	";
		}
		cout << endl;
	}
}
int max(int** b, int n)
{
	int m = *(*(b + 0) + 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*(*(b + i) + j) > m)
				m = *(*(b + i) + j);
		}
	}
	return m;
}